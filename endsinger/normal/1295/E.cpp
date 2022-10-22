#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N*4],lz[N*4];
int p[N],w[N];
void f(int x,int l,int r,int y,int L,int R){
	if(l<=L&&r>=R){
		a[x]+=y;lz[x]+=y;return;
	}
	int m=(L+R)>>1;
	if(l<=m)f(x<<1,l,r,y,L,m);
	if(r>m)f(x<<1|1,l,r,y,m+1,R);
	a[x]=min(a[x<<1],a[x<<1|1])+lz[x];
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n){
		scanf("%d",&w[i]);
		f(1,p[i],n,w[i],0,n);
	}ll tot=0,ans=1e18;
	rep(i,1,n-1){
		tot+=w[i];
		f(1,p[i],n,-w[i]*2,0,n);
		ans=min(ans,a[1]+tot);
	}
	printf("%lld\n",ans);
}