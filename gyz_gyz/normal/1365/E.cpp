#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=1e9+7;
ll a[N];
int main(){int n;ll ans=0;
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,n)rep(j,i,n)rep(k,j,n)ans=max(ans,a[i]|a[j]|a[k]);
	printf("%lld\n",ans);
}