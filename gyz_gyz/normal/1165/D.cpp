#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll Inf=1e18;
void sol(){
	int n;set<ll>s;
	scanf("%d",&n);
	rep(i,1,n){ll x;
		scanf("%lld",&x);
		s.insert(x);
	}
	ll m=*s.begin()**(--s.end());
	rep(i,2,m){
		if(m/i<i)break;
		if(!(m%i)){
			if(!s.count(i)){
				m=-1;break;
			}else s.erase(i);
			if(i!=m/i){
				if(!s.count(m/i)){
					m=-1;break;
				}else s.erase(m/i);
			}
		}
	}
	if(!s.empty())m=-1;
	printf("%lld\n",m);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}