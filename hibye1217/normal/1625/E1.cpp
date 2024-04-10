#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

typedef struct Node{
	pi2 rng = {0, 0};
	vector<int> nxt; int par = -1;
	vector<ll> prf;
	ll cnt = 0;
}Node;
vector<Node> tree;

vector<pi2> v;
int jmp[300020], pmj[300020], num[300020];

void dfs(int now){ Node& nod = tree[now];
	nod.prf.resize( nod.nxt.size() ); int idx = 0;
	for (int nxt : nod.nxt){ dfs(nxt);
		if (idx != 0){ nod.prf[idx] = nod.prf[idx-1]; }
		nod.prf[idx] += tree[nxt].cnt; idx += 1;
	}
	int c = nod.nxt.size();
	if (c != 0){
		nod.cnt = nod.prf[c-1];
		nod.cnt += (ll)c*(c-1)/2;
		nod.cnt += 1;
	}
	else{
		nod.cnt = 1;
	}
}

void Main(){
	int sl, q; cin >> sl >> q;
	string s; cin >> s;
	stack<int> stk;
	memset(jmp, -1, sizeof(jmp));
	for (int i = 0; i < sl; i++){
		if (s[i] == '('){ stk.push(i); }
		else{
			if (!stk.empty()){
				int j = stk.top(); stk.pop();
				v.push_back({j, i}); jmp[j] = i; pmj[i] = j;
			}
		}
	}
	sort(all(v), [](pi2 a, pi2 b){ return a.sc-a.fr < b.sc-b.fr; });
	for (pi2 p : v){
		int st = p.fr, ed = p.sc; int idx = num[st] = tree.size();
		tree.push_back( Node() ); tree[idx].rng = {st, ed};
		int ptr = st+1;
		while (ptr < ed){
			while (ptr < ed && jmp[ptr] == -1){ ptr += 1; }
			if (ptr < ed){
				tree[idx].nxt.push_back(num[ptr]);
				tree[ num[ptr] ].par = idx;
				ptr = jmp[ptr];
			}
		}
	}
	int r = tree.size(); tree.push_back( Node() );
	for (int i = 0; i < sl; i++){
		if (jmp[i] == -1){ continue; }
		int idx = num[i];
		if (tree[idx].par != -1){ continue; }
		tree[idx].par = r;
		tree[r].nxt.push_back(idx);
	}
	dfs(r);
	/* for (int i = 0; i <= r; i++){ Node& nod = tree[i];
		cout << "NODE " << i << ": " << nod.rng.fr << "~" << nod.rng.sc << " / ";
		cout << "["; for (int x : nod.nxt){ cout << x << ", "; } cout << "] ";
		cout << "["; for (int x : nod.prf){ cout << x << ", "; } cout << "] ";
		cout << nod.par << ' ' << nod.cnt;
		cout << endl;
	} */
	while (q--){
		int m, st, ed; cin >> m >> st >> ed; st -= 1; ed -= 1;
		int eds = pmj[ed];
		int idx = tree[ num[st] ].par;
		//cout << "QUERY " << st << "~" << ed << " ("<<eds<<") " << idx << endl;
		//cout << "NODEI " << num[st] << ' ' << num[eds] << endl;
		Node& nod = tree[idx];
		vector<int>& nxt = nod.nxt;
		vector<ll>& prf = nod.prf;
		int ist = upper_bound(all(nxt), num[st], [](int a, int b){ return tree[a].rng.fr < tree[b].rng.fr; }) - nxt.begin();
		int ied = upper_bound(all(nxt), num[eds], [](int a, int b){ return tree[a].rng.fr < tree[b].rng.fr; }) - nxt.begin();
		ist -= 1; ied -= 1;
		//cout << "FOUND " << ist << "~" << ied << endl;
		int c = ied-ist+1;
		ll ans = prf[ied]; if (ist != 0){ ans -= prf[ist-1]; }
		ans += (ll)c*(c-1) / 2;
		cout << ans << endl;
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