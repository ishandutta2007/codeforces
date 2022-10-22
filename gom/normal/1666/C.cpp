#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1000;

pll a[4];

ll dist(pll a, pll b){
	return abs(a.first-b.first) + abs(a.second-b.second);
}

vector<pair<pll, pll> > ans;

void rmv(){
	int idx = 0;
	while(idx<ans.size()){
		if(ans[idx].first.first==ans[idx].second.first && ans[idx].first.second==ans[idx].second.second){
			ans[idx] = ans.back();
			ans.pop_back();
		}else{
			idx++;
		}
	}
}

void print(){
	rmv();
	printf("%d\n", (int)ans.size());
	for(int i=0; i<ans.size(); i++){
		printf("%lld %lld %lld %lld\n", ans[i].first.first, ans[i].first.second, ans[i].second.first, ans[i].second.second);
	}
}

int main(){
	for(int i=0; i<3; i++){
		scanf("%lld%lld", &a[i].first, &a[i].second);
	}
	sort(a, a+3);
	if(a[1].first==a[2].first){
		if(a[0].first==a[1].first){
			ans.pb({a[0], a[2]});
		}else{
			if(a[1].second>=a[0].second){
				ans.pb({a[0], {a[1].first, a[0].second}});
				ans.pb({{a[1].first, a[0].second}, a[1]});
				ans.pb({a[1], a[2]});
			}else if(a[2].second<=a[0].second){
				ans.pb({a[0], {a[2].first, a[0].second}});
				ans.pb({{a[2].first, a[0].second}, a[2]});
				ans.pb({a[1], a[2]});
			}else{
				ans.pb({a[1], a[2]});
				ans.pb({a[0], {a[1].first, a[0].second}});
			}
		}
	}else if(a[1].second>=a[0].second && a[2].second>=a[1].second){
		ans.pb({a[0], {a[1].first, a[0].second}});
		ans.pb({{a[1].first, a[0].second}, a[1]});
		ans.pb({a[1], {a[2].first, a[1].second}});
		ans.pb({{a[2].first, a[1].second}, a[2]});
	}else if(a[1].second<=a[0].second && a[2].second<=a[1].second){
		ans.pb({a[0], {a[1].first, a[0].second}});
		ans.pb({{a[1].first, a[0].second}, a[1]});
		ans.pb({a[1], {a[2].first, a[1].second}});
		ans.pb({{a[2].first, a[1].second}, a[2]});
	}else if(a[1].second>=a[0].second){
		if(a[2].second>=a[0].second && dist(a[0], a[2]) + dist(a[1], a[2]) > dist(a[0], a[2]) + abs(a[1].second-a[2].second)){
			ans.pb({a[0], {a[0].first, a[2].second}});
			ans.pb({{a[0].first, a[2].second}, a[2]});
			ans.pb({a[1], {a[1].first, a[2].second}});
		}else if(dist(a[0], a[2]) + dist(a[1], a[2]) < dist(a[0], a[2]) + abs(a[0].second-a[1].second)){
			ans.pb({a[0], {a[2].first, a[0].second}});
			ans.pb({{a[2].first, a[0].second}, a[2]});			
			ans.pb({a[1], {a[1].first, a[2].second}});
			ans.pb({{a[1].first, a[2].second}, a[2]});
		}else{
			ans.pb({a[0], {a[2].first, a[0].second}});
			ans.pb({{a[2].first, a[0].second}, a[2]});		
			ans.pb({a[1], {a[1].first, a[0].second}});
		}
	}else{
		if(a[2].second<=a[0].second && dist(a[0], a[2]) + dist(a[1], a[2])>dist(a[0], a[2]) + abs(a[1].second-a[2].second)){
			ans.pb({a[0], {a[0].first, a[2].second}});
			ans.pb({{a[0].first, a[2].second}, a[2]});
			ans.pb({a[1], {a[1].first, a[2].second}});
		}else if(dist(a[0], a[2]) + dist(a[1], a[2]) < dist(a[0], a[2]) + abs(a[0].second-a[1].second)){
			ans.pb({a[0], {a[2].first, a[0].second}});
			ans.pb({{a[2].first, a[0].second}, a[2]});			
			ans.pb({a[1], {a[1].first, a[2].second}});
			ans.pb({{a[1].first, a[2].second}, a[2]});
		}else{
			ans.pb({a[0], {a[2].first, a[0].second}});
			ans.pb({{a[2].first, a[0].second}, a[2]});		
			ans.pb({a[1], {a[1].first, a[0].second}});
		}
	}
	print();
	return 0;
}