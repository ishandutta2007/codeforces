#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
ll a[N],b[N],f[N],g[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,n)scanf("%lld",&b[i]);
	rep(i,1,n){
		f[i]=max(f[i-1],g[i-1]+a[i]);
		g[i]=max(g[i-1],f[i-1]+b[i]);
	}
	printf("%lld\n",max(f[n],g[n]));
}