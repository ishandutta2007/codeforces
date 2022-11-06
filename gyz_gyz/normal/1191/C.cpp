#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
ll a[N];
int main(){ll n,k;int m;
	scanf("%lld%d%lld",&n,&m,&k);
	int nw=0,ans=0;
	rep(i,1,m){
		scanf("%lld",&a[i]);
		if(i==1||(a[i]-nw)/k!=(a[i-1]-nw)/k){
			nw=i;++ans;
		}
	}
	printf("%d\n",ans);;
}