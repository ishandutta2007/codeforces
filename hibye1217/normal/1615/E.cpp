#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ld = long double;

#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;

#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

typedef pair<pl2, pl2> pl4;

ll n, m;
vector<int> adj[200020];
ll dep[200020]; pl2 nxp[200020];

void dfs(int now, int par, int dpt){
	dep[now] = dpt;
	nxp[now] = {0, dpt};
	for (int nxt : adj[now]){
		if (nxt == par){ continue; }
		dfs(nxt, now, dpt+1);
		if (nxp[now].sc < nxp[nxt].sc){
			nxp[now].fr = nxt;
			nxp[now].sc = nxp[nxt].sc;
		}
	}
}

priority_queue<pl2> pq;
bool chk[200020];
void dfs2(int now){
	chk[now] = 1;
	for (int nxt : adj[now]){
		if (chk[nxt]){ continue; }
		if (nxp[now].fr == nxt){ dfs2(nxt); }
		else{
			pq.push({nxp[nxt].sc - dep[now], nxt});
		}
	}
}

ll ans = -1e18;
vector<ll> arr, prf, suf;
void Main(){
	cin >> n >> m;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1, 1);
	pq.push({ nxp[1].sc, 1 });
	while (!pq.empty()){
		int dep = pq.top().fr, now = pq.top().sc;
		//cout << "PQ " << dep << ' ' << now << endl;;
		dfs2(now); pq.pop();
		arr.push_back(dep);
	}
	int al = arr.size();
	prf.resize(al); suf.resize(al);
	prf[0] = arr[0]; suf[al-1] = arr[al-1];
	for (int i = 1; i < al; i++){ prf[i] = prf[i-1] + arr[i]; }
	for (int i = al-2; i >= 0; i--){ suf[i] = suf[i+1] + arr[i]; }
	for (int i = 0; i < al; i++){
		if (i+1 > m){ break; }
		ll r = i+1;
		r = max( r, min({ prf[i], m, n/2LL }) );
		ll b = 0;
		if (i+1 != al){ b = min(suf[i+1], n/2); }
		ll res = (n-r-b) * (r-b);
		ans = max(ans, res);
	}
	cout << ans;
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}