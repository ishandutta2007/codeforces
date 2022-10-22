#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=150010;
struct node{
	int c[6][2];
};
struct tree{
	int l,r,lc,rc;node c;
}tr[2*N];int len=0;
void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	memset(tr[now].c.c,60,sizeof(tr[now].c.c));
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
	}
}
int cnt,bz[2*N];
void update(int now){
	if(bz[now]>0){
		int mid=(tr[now].l+tr[now].r)>>1;
		int lc=tr[now].lc,rc=tr[now].rc;
		memset(tr[lc].c.c,60,sizeof(tr[lc].c.c));
		memset(tr[rc].c.c,60,sizeof(tr[rc].c.c));
		tr[lc].c.c[1][0]=tr[rc].c.c[1][0]=bz[now];
		tr[lc].c.c[1][1]=mid-tr[now].l+1;tr[rc].c.c[1][1]=tr[now].r-mid;
		bz[lc]=bz[rc]=bz[now];
		bz[now]=0;
	}
}
int g[13][2];
node merge(node n1,node n2){
	node no;
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			if(n1.c[i][0]==n2.c[j][0]&&n1.c[i][0]<1e9)
				n1.c[i][1]+=n2.c[j][1],n2.c[j][0]=1e9;
	int sum=0;
	for(int i=1;i<=cnt;i++){
		if(n1.c[i][0]<1e9) g[++sum][0]=n1.c[i][0],g[sum][1]=n1.c[i][1];
		if(n2.c[i][0]<1e9) g[++sum][0]=n2.c[i][0],g[sum][1]=n2.c[i][1];
	}
	for(int i=1;i<=cnt;i++)
		for(int j=sum;j>1;j--)
			if(g[j][1]>g[j-1][1])
				swap(g[j][0],g[j-1][0]),swap(g[j][1],g[j-1][1]);
	for(int i=1;i<=cnt;i++){
		no.c[i][0]=g[i][0],no.c[i][1]=g[i][1];
		if(sum>cnt) no.c[i][1]-=g[cnt+1][1];
		if(i>sum) no.c[i][0]=no.c[i][1]=1e9;
	}
	return no;
}
void change(int now,int l,int r,int c){
	if(tr[now].l==l&&tr[now].r==r){
		memset(tr[now].c.c,60,sizeof(tr[now].c.c));
		tr[now].c.c[1][0]=c;tr[now].c.c[1][1]=r-l+1;
		bz[now]=c;
		return ;
	}
	update(now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) change(lc,l,r,c);
	else if(mid<l) change(rc,l,r,c);
	else change(lc,l,mid,c),change(rc,mid+1,r,c);
	tr[now].c=merge(tr[lc].c,tr[rc].c);
}
node findans(int now,int l,int r){
	if(l==tr[now].l&&r==tr[now].r) return tr[now].c;
	update(now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) return findans(lc,l,r);
	else if(mid<l) return findans(rc,l,r);
	else return merge(findans(lc,l,mid),findans(rc,mid+1,r));
}
int main()
{
	int n,m,p;scanf("%d%d%d",&n,&m,&p);
	cnt=100/p;
	build(1,n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		change(1,i,i,x);
	}
	for(int i=1;i<=m;i++){
		int id;scanf("%d",&id);
		if(id==1){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			change(1,l,r,c);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			node t=findans(1,l,r);
			printf("%d",cnt);
			for(int j=1;j<=cnt;j++){
				if(t.c[j][0]>=1e9) printf(" 1000");
				else printf(" %d",t.c[j][0]);
			}
			printf("\n");
		}
	}
	return 0;
}