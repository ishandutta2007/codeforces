#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e6+10;
const int mo=998244353;
int main(){ll x,y,z;
	scanf("%lld%lld%lld",&x,&y,&z);
	x=min(x,y+1);y=min(y,x+1);
	printf("%lld\n",x+y+z*2);
}