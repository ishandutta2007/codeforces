#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;

vector<pllll> w;
vector<pll> v[100020];
bool chk[100020];
ll n, m;

ll dfs(int now){
	chk[now] = true;
	bool lp = true;
	ll sum = 0;
	for (pll nod : v[now]){
		ll nxt = get<0>(nod), dis = get<1>(nod);
		if (chk[nxt]) continue;
		lp = false;
		ll cnt = dfs(nxt);
		sum += cnt;
		w.push_back({now, nxt, cnt, dis});
	}
	if (lp) return 1;
	return sum;
}

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i < n; i++){
			int x, y, z;
			cin >> x >> y >> z;
			v[x].push_back({y, z});
			v[y].push_back({x, z});
		}
		ll _ = dfs(1);
		priority_queue<pllll> pq;
		ll sum = 0;
		for (pllll e : w){
			ll x = get<0>(e), y = get<1>(e), cnt = get<2>(e), dis = get<3>(e);
			pq.push({cnt*(dis - dis/2), cnt, cnt*dis, dis});
			sum += cnt*dis;
		}
		ll ans = 0;
		while (sum > m){
			pllll e = pq.top();
			ll dcs = get<0>(e), cnt = get<1>(e), cst = get<2>(e), dis = get<3>(e);
			dis /= 2;
			pq.pop(); pq.push({cnt*(dis - dis/2), cnt, cnt*dis, dis});
			sum -= dcs; ans += 1;
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++) v[i].clear();
		w.clear();
		for (int i = 1; i <= n; i++) chk[i] = false;
	}
}