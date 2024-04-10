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
int main(){ll u,v;
	scanf("%lld%lld",&u,&v);
	if(u>v||u%2!=v%2)return printf("-1\n"),0;
	if(!u&&!v)return printf("0\n"),0;
	if(u==v)return printf("1\n%lld\n",u),0;
	if(!u)return printf("2\n%lld %lld\n",v/2,v/2),0;
	ll r=(v-u)/2;
	if(!(u&r))printf("2\n%lld %lld\n",u^r,r);
	else printf("3\n%lld %lld %lld\n",u,r,r);
}