#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll u,v,p;
map<ll,int>M;
map<ll,int>pre,pre2;
queue<int>x,y;
bool in(int val,int rn){
	return ((M.find(val) != M.end()) & (((M[val]>>rn)&1)));
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%p;
		x=x*x%p;
		n>>=1;
	}
	return res;
}
int main(){
	cin>>u>>v>>p;
	x.push(u);
	y.push(v);
	for(int i=0;;i++){
		int sz = x.size();
		bool en = false;
		int goal = -1;
		while(sz--){
			int q = x.front(); x.pop();
			
			if(in(q,0)) continue;
			M[q] |= 1;
			if(M[q] == 3){
				en = true;
				goal = q;
				break;
			}
			if(!in((q+p-1)%p,0)){
				x.push((q+p-1)%p);
				pre[(q+p-1)%p] = q;
			}
			if(!in((q+1)%p,0)){
				x.push((q+1)%p);
				pre[(q+1)%p] = q;
			}
			ll rev = modpow(q,p-2);
			if(!in(rev,0)){
				x.push(rev);
				pre[rev] = q;
			}
		}
		sz = y.size();
		while(sz--){
			int q = y.front(); y.pop();
			if(in(q,1)) continue;
			M[q] |= 2;
			if(M[q] == 3){
				en = true;
				goal = q;
				break;
			}
			if(!in((q+p-1)%p,1)){
				y.push((q+p-1)%p);
				pre2[(q+p-1)%p] = q;
			}
			if(!in((q+1)%p,1)){
				y.push((q+1)%p);
				pre2[(q+1)%p] = q;
			}
			ll rev = modpow(q,p-2);
			if(!in(rev,1)){
				y.push(rev);
				pre2[rev] = q;
			}
		}
		if(en){
			vector<int>num;
			int cur = goal;
			num.pb(cur);
			while(cur != u){
				cur = pre[cur];
				num.pb(cur);
			}
			reverse(num.begin(),num.end());
			cur = goal;
			while(cur != v){
				cur = pre2[cur];
				num.pb(cur);
			}
			cout<<num.size()-1<<endl;
			for(int i=1;i<num.size();i++){
				ll a = num[i-1];
				ll b = num[i];
				if((a+1)%p == b){
					printf("1 ");
				}
				else if((a+p-1)%p == b){
					printf("2 ");
				}
				else printf("3 ");
			}
			puts("");
			return 0;
		}
	}
}