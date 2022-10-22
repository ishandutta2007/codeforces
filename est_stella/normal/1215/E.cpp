#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0)
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 1e18;
const int inf = 1e9;

int n;
int a[400010];
ll cost[40][40];
vector<int> v[40];
ll dp[1100100];

int main() {
	fast;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		v[a[i]].eb(i);
	}

	for(int i=0; i<n; i++) {
		for(int j=1; j<=20; j++) {
			if(a[i] == j) continue;
			ll t = lower_bound(all(v[j]), i) - v[j].begin();
			cost[a[i]][j] += v[j].size() - t;
		}
 	}

 	for(int i=1; i < (1<<20); i++) {
 		dp[i] = INF;
 		
 		for(int j=0; j<20; j++) {
 			if(i & (1<<j)) {
 				ll sum = 0;
 				for(int k=0; k<20; k++) {
 					if((i ^ (1<<j)) & (1<<k)) {
 						sum += cost[j+1][k+1];
 					}
 				}
 				dp[i] = min(dp[i], dp[i ^ (1<<j)] + sum);
 			}
 		}
 	}

 	cout << dp[(1<<20)-1];
}