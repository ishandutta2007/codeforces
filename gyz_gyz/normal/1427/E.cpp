#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e6+10;
const int mo=998244353;
const ll inf=1e18;
struct pr{ll x,y;bool op;};
vector<pr>res;int tot;
int cal(ll x){
	dep(i,59,0)if((x>>i)&1)return i;
	return 64;
}
int sol(ll n){
	res.push_back({n,n,1});
	rep(i,1,2000000){int fl=0;
		if(cal(n^(n*i)^(n*(i-1)))<cal(n)&&((n^(n*i)^(n*(i-1)))&1))fl=1;
		else if(cal((n*2)^(n*i)^(n*(i-1)))<cal(n)&&(((n*2)^(n*i)^(n*(i-1)))&1))fl=2;
		else if(cal(n^(n*2)^(n*i)^(n*(i-1)))<cal(n)&&((n^(n*2)^(n*i)^(n*(i-1)))&1))fl=3;
		if(fl){
			int t=cal(i);
			rep(j,1,t-1)res.push_back({n<<j,n<<j,1});
			ll nw=0;
			rep(j,0,t)if(((i-1)>>j)&1){
				if(nw)res.push_back({n*nw,n<<j,1});
				nw+=1<<j;
			}nw=0;
			rep(j,0,t)if((i>>j)&1){
				if(nw)res.push_back({n*nw,n<<j,1});
				nw+=1<<j;
			}
			res.push_back({n*(i-1),n*i,0});
			nw=(n*(i-1))^(n*i);
			if(fl&1){
				res.push_back({nw,n,0});
				nw^=n;
			}
			if(fl&2){
				res.push_back({nw,n*2,0});
				nw^=n*2;
			}
			return nw;
		}
	}
	return -1;
}
int main(){ll n;
	scanf("%lld",&n);
	while(n>1)n=sol(n);
	printf("%d\n",(int)res.size());
	for(auto&i:res)printf("%lld %c %lld\n",i.x,i.op?'+':'^',i.y);
}