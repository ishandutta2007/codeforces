#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
struct node{
	int a[3],b[3];
};
struct tree{
	int l,r,lc,rc,bz;node c;
}tr[2*N];int len=0;
void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	for(int i=0;i<=2;i++) tr[now].c.a[i]=i;
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
	}
}
node merge(node n1,node n2){
	node no;
	for(int i=0;i<=2;i++){
		no.a[i]=n1.a[n2.a[i]];
		no.b[i]=n2.b[i]+n1.b[n2.a[i]];
	}
	return no;
}
void Change(int now,int k,int c,int ty){
	if(tr[now].l==tr[now].r){
		tr[now].bz^=c;
		if(tr[now].bz==0){
			for(int i=0;i<=2;i++)
				tr[now].c.a[i]=i,tr[now].c.b[i]=0;
		}
		else if(tr[now].bz!=3){
			tr[now].c.a[0]=tr[now].bz;tr[now].c.b[0]=0;
			tr[now].c.a[tr[now].bz]=tr[now].bz;tr[now].c.b[tr[now].bz]=0;
			tr[now].c.a[3-tr[now].bz]=0;tr[now].c.b[3-tr[now].bz]=1;
		}
		else{
			for(int i=0;i<=2;i++)
				tr[now].c.a[i]=0,tr[now].c.b[i]=1;
		}
		return ;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=mid) Change(lc,k,c,ty);
	else Change(rc,k,c,ty);
	tr[now].c=merge(tr[lc].c,tr[rc].c);
	
}
node findans(int now,int l,int r){
	if(l==tr[now].l&&r==tr[now].r) return tr[now].c;
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) return findans(lc,l,r);
	else if(mid<l) return findans(rc,l,r);
	else return merge(findans(lc,l,mid),findans(rc,mid+1,r));
}

int a[N],Cnt1[N],Cnt2[N];

int main()
{
	
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	build(0,n);
	for(int i=2;i<=n;i++){
		if(!Cnt2[a[i]]){
			Change(1,a[i],2,1);
		}
		Cnt2[a[i]]++;
	}
	if(!Cnt1[0]){
		Change(1,0,1,1);
	}
	Cnt1[0]++;
	if(!Cnt2[0]){
		Change(1,0,2,1);
	}
	Cnt2[0]++;
	
	ll Ans=0;
	if(a[1]) Ans+=findans(1,0,a[1]-1).b[0];
	for(int i=2;i<=n;i++){
		Cnt2[a[i]]--;
		if(!Cnt2[a[i]]) Change(1,a[i],2,-1);
		if(!Cnt1[a[i-1]]) Change(1,a[i-1],1,1);
		Cnt1[a[i-1]]++;
		if(a[i]) Ans+=findans(1,0,a[i]-1).b[0];
	}
	
	printf("%lld\n",Ans);
	
	return 0;
}