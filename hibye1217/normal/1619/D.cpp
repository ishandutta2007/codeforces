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
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )

// #define DEBUG

typedef pair<pl2, pl2> pl4;
vector<pl2> arr[100020];
bool chk[100020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> m >> n;
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				ll x; cin >> x;
				arr[j].push_back({i, x});
			}
		}
		ll mn = 1e15;
		for (int i = 1; i <= n; i++){
			sort(all(arr[i]), [](pl2 a, pl2 b){
				return a.sc > b.sc;
			});
		}
		priority_queue<pl4> pq;
		for (int i = 1; i <= n; i++){
			pq.push({ {arr[i][0].sc, arr[i][0].fr}, {i, 0} });
			mn = min(mn, arr[i][0].sc);
		}
		while (!pq.empty()){
			ll val = pq.top().fr.fr, shp = pq.top().fr.sc;
			int per = pq.top().sc.fr, idx = pq.top().sc.sc;
			pq.pop();
			//cout << "PQ " << val << ' ' << shp << ' ' << per << ' ' << idx << endl;
			if (idx != m-1){
				pq.push({ {arr[per][idx+1].sc, arr[per][idx+1].fr}, {per, idx+1} });
			}
			mn = min(mn, val);
			if (chk[shp]){ cout << mn << endl; break; }
			chk[shp] = 1;
		}
		for (int i = 1; i <= n; i++){ arr[i].clear(); }
		for (int i = 1; i <= m; i++){ chk[i] = 0; }
	}
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