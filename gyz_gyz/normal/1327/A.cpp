#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
bool sol(){ll n,k;
	scanf("%lld%lld",&n,&k);
	return n%2==k%2&&k*k<=n;
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)printf("%s\n",sol()?"YES":"NO");
}