#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+100;
struct tree{
	int l,r,lc,rc,c1;
}tr[2*N];int len=0;
void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	tr[now].c1=0;
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
	}
}
void change(int now,int k,int c){
	if(tr[now].l==tr[now].r){
		tr[now].c1+=c;
		return ;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=mid) change(lc,k,c);
	else change(rc,k,c);
	tr[now].c1=tr[lc].c1+tr[rc].c1;
}
int findl(int now,int l){
	if(tr[now].c1==0) return -1;
	if(tr[now].l==tr[now].r) return tr[now].l;
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(l<=mid){
		int t=findl(lc,l);
		if(t==-1) return findl(rc,mid+1);
		return t;
	}
	else return findl(rc,l);
}
int a[N],nex[N],Ans[N],b[N];
int gcd(int A,int B){
	if(A==0) return B;
	return gcd(B%A,A);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		len=0;build(1,n);
		for(int i=1;i<n;i++) nex[i]=i+1;
		nex[n]=1;
		for(int i=1;i<=n;i++){
			b[i]=gcd(a[i],a[nex[i]]);
			if(b[i]==1) change(1,i,1);
		}
		int t=findl(1,1);Ans[0]=0;
		while(t!=-1){
			Ans[++Ans[0]]=nex[t];
			if(b[nex[t]]==1) change(1,nex[t],-1);
			if(t==nex[t]) break;
			nex[t]=nex[nex[t]];
			b[t]=gcd(a[t],a[nex[t]]);
			if(b[t]!=1) change(1,t,-1);
			t=findl(1,nex[t]);
			if(t==-1) t=findl(1,1);
		}
		printf("%d ",Ans[0]);
		for(int i=1;i<=Ans[0];i++) printf("%d ",Ans[i]);
		printf("\n");
	}
	return 0;
}