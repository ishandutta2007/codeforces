#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
int f[2][N];
int main(){int n,h,l,r;
	scanf("%d%d%d%d",&n,&h,&l,&r);
	int t=0;
	rep(i,1,h-1)f[0][i]=-inf;
	rep(i,1,n){t^=1;int x;
		scanf("%d",&x);
		rep(i,0,h-1)
			f[t][i]=max(f[t^1][(i+h-x)%h],f[t^1][(i+h-x+1)%h])+(i>=l&&i<=r);
	}int ans=0;
	rep(i,0,h-1)ans=max(ans,f[t][i]);
	printf("%d\n",ans);
}