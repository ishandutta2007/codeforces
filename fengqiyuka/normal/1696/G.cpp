#include<bits/stdc++.h>
using namespace std;

typedef double db;
const int N=2e5+100;
int a[N],X,Y;

struct node{
	int L,R;db a[3][3],s;
};
struct tree{
	int l,r,lc,rc;node c;
}tr[2*N];int len=0;
void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
	}
}
db mymax(db x,db y) {return (x>y?x:y);}
node merge(node n1,node n2){
	node no;
	no.L=n1.L;no.R=n2.R;no.s=n1.s+n2.s;
	memset(no.a,-60,sizeof(no.a));
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
			for(int k=0;k<=2;k++)
				for(int l=0;l<=2;l++){
					if(j==1&&k==1) continue;
					db t=n1.a[i][j]+n2.a[k][l];
					if(k==1&&j==0) t=t-n1.R;
					if(j==1&&k==0) t=t-n2.L;
					
					int t1=i,t2=l;
					if(n2.s==n2.R&&j==1) t2=2;
					if(n1.s==n1.L&&k==1) t1=2;
					
					no.a[t1][t2]=mymax(no.a[t1][t2],t);
				}
	return no;
}
void Change(int now,int k,int c){
	if(tr[now].l==tr[now].r){
		tr[now].c.L=tr[now].c.R=c;
		memset(tr[now].c.a,-60,sizeof(tr[now].c.a));
		tr[now].c.a[0][0]=0;
		tr[now].c.a[1][1]=c*1.0/Y*X;
		tr[now].c.s=c;
		return ;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=mid) Change(lc,k,c);
	else Change(rc,k,c);
	tr[now].c=merge(tr[lc].c,tr[rc].c); 
}
node findans(int now,int l,int r){
	if(tr[now].l==l&&r==tr[now].r) return tr[now].c;
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) return findans(lc,l,r);
	else if(mid<l) return findans(rc,l,r);
	else return merge(findans(lc,l,mid),findans(rc,mid+1,r));
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	
	scanf("%d%d",&X,&Y);
	if(X>Y) swap(X,Y);
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	build(1,n);
	for(int i=1;i<=n;i++) Change(1,i,a[i]);
	for(int i=1;i<=q;i++){
		int op;scanf("%d",&op);
		if(op==1){
			int x,c;
			scanf("%d%d",&x,&c);
			Change(1,x,c);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			node t=findans(1,l,r);
			db Ans=0;
			for(int i=0;i<=2;i++)
				for(int j=0;j<=2;j++)
					Ans=mymax(Ans,t.a[i][j]);
			
			printf("%.10lf\n",(Ans+t.s)/(X+Y));
		}
		
	}
	
	return 0;
}