#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
int main(){ll k,d,t;
	scanf("%lld%lld%lld",&k,&d,&t);
	d+=d*((k-1)/d);t*=2;
	ll r=d+k;double ans=t/r*d;t%=r;
	if(t<=k*2)return printf("%.11lf\n",ans+t*0.5),0;
	ans+=k;t-=k*2;
	printf("%.11lf\n",ans+t);
}