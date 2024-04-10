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
void sol(){ll n,k,ans=-1;
	scanf("%lld%lld",&n,&k);
	for(;n;n/=k)ans+=n%k+1;
	printf("%lld\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol(); 
}