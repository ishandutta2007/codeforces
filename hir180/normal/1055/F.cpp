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
unordered_map<ll,int>M;
int n;
ll num;
vector<pair<int,ll> >edge[1000005];
ll rui[1000005];
void dfs(int v,ll r){
	rui[v] = r;
	for(int i=0;i<edge[v].size();i++){
		int to = edge[v][i].fi;
		ll rr = (r^edge[v][i].sc);
		dfs(to,rr);
	}
}
P my[10000005],you[10000005];
int nxt = 1;
int main(){
	scanf("%d%lld",&n,&num); //n= 1000000; num = 1000000000000LL; 
	for(int i=1;i<n;i++){
		int a; ll b;
		scanf("%d%lld",&a,&b);
		edge[a].pb(mp(i+1,b));
	}
	dfs(1,0);
	ll ans = 0;
	sort(rui+1,rui+n+1);
	
	my[nxt] = mp(1,n);
	you[nxt++] = mp(1,n);
	
	for(int x=61;x>=0;x--){
		ll N = 0;
		for(int i=1;i<nxt;i++){
			if(you[i].fi > you[i].sc) continue;
			ll a0=0,a1=0;
			ll b0=0,b1=0;
			for(int xx=my[i].fi;xx<=my[i].sc;xx++){
				ll v = rui[xx];
				if(((v>>x)&1LL)){
					a1 = my[i].sc-my[i].fi+1-a0;
					break;
				}
				else a0++;
			}
			for(int xx=you[i].fi;xx<=you[i].sc;xx++){
				ll v = rui[xx];
				if(((v>>x)&1LL)){
					b1 = you[i].sc-you[i].fi+1-b0;
					break;
				}
				else b0++;
			}
			N += (a0*b0+a1*b1);
		}
		if(N >= num){
			int prenxt = nxt;
			for(int i=1;i<prenxt;i++){
				if(you[i].fi > you[i].sc) continue;
				ll a0=0,a1=0;
				ll b0=0,b1=0;
    			for(int xx=my[i].fi;xx<=my[i].sc;xx++){
    				ll v = rui[xx];
    				if(((v>>x)&1LL)){
    					a1 = my[i].sc-my[i].fi+1-a0;
    					break;
    				}
    				else a0++;
    			}
    			for(int xx=you[i].fi;xx<=you[i].sc;xx++){
    				ll v = rui[xx];
    				if(((v>>x)&1LL)){
    					b1 = you[i].sc-you[i].fi+1-b0;
    					break;
    				}
    				else b0++;
    			}
				if(a0){
					my[i].sc = my[i].fi+a0-1;
					you[i].sc = you[i].fi+b0-1;
					if(a1){
						my[nxt] = mp(my[i].sc+1,my[i].sc+a1);
						you[nxt++] = mp(you[i].sc+1,you[i].sc+b1);
					}
				}
				else{
					you[i].fi = you[i].sc-b1+1;
				}
			}
		}
		else{
			num-=N;
			ans += (1LL<<x);
			int prenxt = nxt;
			for(int i=1;i<prenxt;i++){
				if(you[i].fi > you[i].sc) continue;
				ll a0=0,a1=0;
				ll b0=0,b1=0;
    			for(int xx=my[i].fi;xx<=my[i].sc;xx++){
    				ll v = rui[xx];
    				if(((v>>x)&1LL)){
    					a1 = my[i].sc-my[i].fi+1-a0;
    					break;
    				}
    				else a0++;
    			}
    			for(int xx=you[i].fi;xx<=you[i].sc;xx++){
    				ll v = rui[xx];
    				if(((v>>x)&1LL)){
    					b1 = you[i].sc-you[i].fi+1-b0;
    					break;
    				}
    				else b0++;
    			}
				if(a0){
					my[i].sc = my[i].fi+a0-1;
					you[i].fi = you[i].sc-b1+1;
					if(a1){
						my[nxt] = mp(my[i].sc+1,my[i].sc+a1);
						you[nxt++] = mp(you[i].fi-b0,you[i].fi-1);
					}
				}
				else{
					you[i].sc = you[i].fi+b0-1;
				}
			}
		}
	}
	//assert(num == 0);
	cout<<ans<<endl;
}