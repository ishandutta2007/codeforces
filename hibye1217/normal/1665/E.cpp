#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const int N = 30;

struct Node{ vector<int> pos; int nxt[2] = {}; };
vector<Node> trie;
void upd(int idx, int pos, int val, int bit){
	trie[idx].pos.push_back(pos);
	if (bit == 0){ return; }
	int nxt = (val&bit) ? 1 : 0;
	if (trie[idx].nxt[nxt] == 0){
		trie[idx].nxt[nxt] = trie.size();
		trie.push_back( Node() );
	}
	upd(trie[idx].nxt[nxt], pos, val, bit>>1);
}

int m = 0, pos[40];
int qry(int dep, int st, int ed){
	//cout << "QUERY " << dep << ' ' << st << ' ' << ed << endl;
	//cout << "POS "; for (int i = 1; i <= m; i++){ cout << pos[i] << ' '; }
	//cout << endl;
	if (dep < 0){ return 0; }
	int cnt = 0;
	for (int i = 1; i <= m; i++){
		int idx = pos[i];
		int nxt = trie[idx].nxt[0];
		if (nxt == 0){ continue; }
		auto num = upper_bound(all(trie[nxt].pos), ed) - lower_bound(all(trie[nxt].pos), st);
		cnt += num;
	}
	//cout << endl << cnt << endl;
	if (cnt >= 2){
		int p = 1;
		for (int i = 1; i <= m; i++){
			int idx = pos[i];
			int nxt = trie[idx].nxt[0];
			if (nxt != 0){ pos[p] = nxt; p += 1; }
		}
		m = p-1; return qry(dep-1, st, ed);
	}
	else{
		int p = 1;
		int tmp[40] = {};
		for (int i = 1; i <= m; i++){
			int idx = pos[i];
			int nxt = trie[idx].nxt[0];
			if (nxt != 0){
				auto num = upper_bound(all(trie[nxt].pos), ed) - lower_bound(all(trie[nxt].pos), st);
				if (num > 0){ tmp[p] = nxt; p += 1; }
			}
			nxt = trie[idx].nxt[1];
			if (nxt != 0){
				auto num = upper_bound(all(trie[nxt].pos), ed) - lower_bound(all(trie[nxt].pos), st);
				if (num > 0){ tmp[p] = nxt; p += 1; }
			}
		}
		m = p-1; for (int i = 1; i <= m; i++){ pos[i] = tmp[i]; }
		return qry(dep-1, st, ed) + (1<<dep);
	}
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		trie.push_back( Node() );
		for (int i = 1; i <= n; i++){
			int x; cin >> x; upd(0, i, x, 1<<(N-1));
		}
		int q; cin >> q;
		while (q--){
			int st, ed; cin >> st >> ed;
			m = 1; pos[1] = 0;
			cout << qry(N-1, st, ed) << endl;
		}
		trie.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}