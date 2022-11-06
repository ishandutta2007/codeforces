#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+50;
const int mo=1e9+7;
const int inf=1e9;
void sol(){ll x,y,a,b;
	scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
	printf("%lld\n",(y-x)%(a+b)?-1:(y-x)/(a+b));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}