#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
const ll inf=(1ll<<32)-1;
ll w[N];
int main(){int n,t=0;ll ans=0;
	scanf("%d",&n);w[0]=1;
	rep(i,1,n){
		string s;cin>>s;
		if(s=="add")ans=min(inf+1,ans+w[t]);
		if(s=="for"){ll x;
			scanf("%lld",&x);++t;
			w[t]=min(inf+1,w[t-1]*x);
		}
		if(s=="end")--t;
	}
	if(ans<=inf)printf("%lld\n",ans);else printf("OVERFLOW!!!\n");
}