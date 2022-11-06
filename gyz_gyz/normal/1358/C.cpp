#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
int a[N];
void sol(){ll X1,Y1,X2,Y2;
	scanf("%lld%lld%lld%lld",&X1,&Y1,&X2,&Y2);
	ll n=X2-X1+Y2-Y1,m=X2-X1;
	ll s1=(n+n-m+1)*m/2,s2=(1+m)*m/2;
	printf("%lld\n",s1-s2+1);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}