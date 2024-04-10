#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int mo=998244353;
void sol(){ll x,y;
	scanf("%lld%lld",&x,&y);
	y/=__gcd(x,y);ll res=1;
	rep(i,2,y){
		if(y/i<i)break;
		if(!(y%i)){
			res*=i-1;y/=i;
			while(!(y%i))y/=i,res*=i;
		}
	}
	if(y>1)res*=y-1;
	printf("%lld\n",res);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}