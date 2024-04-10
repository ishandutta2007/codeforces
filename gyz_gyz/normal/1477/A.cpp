#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e3+10;
const int mo=1e9+7;
const ll inf=1e18;
void sol(){int n;ll k,x,y;
	scanf("%d%lld%lld%lld",&n,&k,&x,&y);
	y-=x;k-=x;
	rep(i,3,n){ll z;
		scanf("%lld",&z);
		y=__gcd(y,z-x);
	}
	printf("%s\n",k%y?"NO":"YES");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}