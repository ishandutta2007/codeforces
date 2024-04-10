#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
int w[N],a[N],r[N];
int main(){int n,m,mx=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&w[i]);
		if(mx>w[i]){
			r[1]=max(r[1],w[i]-1);
			r[w[i]+1]=max(r[w[i]+1],mx-1);
		}else mx=w[i];
	}int mi=m+1;
	dep(i,n,1)if(mi<w[i])r[w[i]+1]=m;else mi=w[i];
	ll ans=1ll*m*(m+1)/2;int rs=0;
	rep(i,1,m){
		rs=max(rs,r[i]);
		if(rs>=i)ans-=rs-i+1;
	}
	printf("%lld\n",ans);
}