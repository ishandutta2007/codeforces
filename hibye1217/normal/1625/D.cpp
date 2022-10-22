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

typedef struct Node{ int idx = -1; int nxt[2] = {-1, -1}; };
vector<Node> trie;
pl2 arr[300020];

ll k;
int fnd(int now, ll& num, int b){
	//cout << "FND " << now << ' ' << num << ' ' << b << endl;
	if (b < 0){ return trie[now].idx; }
	ll bit = 1LL << b;
	int idx = (num & bit) ? 1 : 0;
	int i1 = trie[now].nxt[idx];
	int i2 = trie[now].nxt[1-idx];
	if (k & bit){
		if (i2 == -1){ return -1; }
		else{ return fnd(i2, num, b-1); }
	}
	else{
		if (i2 != -1){ return trie[i2].idx; }
		else{ return fnd(i1, num, b-1); }
	}
}

void psh(int now, ll& ii, ll& num, int b){
	trie[now].idx = ii;
	if (b < 0){ return; }
	ll bit = 1LL << b;
	int idx = (num & bit) ? 1 : 0;
	int i1 = trie[now].nxt[idx];
	if (i1 == -1){
		i1 = trie[now].nxt[idx] = trie.size();
		trie.push_back( Node() );
	}
	psh(i1, ii, num, b-1);
}

void Main(){
	int n; cin >> n >> k;
	if (k == 0){
		cout << n << endl;
		for (int i = 1; i <= n; i++){ cout << i << ' '; }
		return;
	}
	int b = 0; ll bit = 1; while (bit <= k){ bit <<= 1; b += 1; } bit -= 1; b -= 1;
	for (int i = 1; i <= n; i++){
		cin >> arr[i].fr; arr[i].sc = i;
	}
	sort(arr+1, arr+n+1);
	int st = 1; vector<ll> ans;
	while (st <= n){
		int ed = st;
		while (ed <= n){
			ll val = arr[st].fr ^ arr[ed].fr;
			if ( (val&~bit) == 0 ){ ed += 1; }
			else{ break; }
		}
		trie.push_back( Node() );
		for (int i = st; i < ed; i++){
			int res = fnd(0, arr[i].fr, b);
			if (res != -1){
				ans.push_back(res); ans.push_back(arr[i].sc);
				goto done;
			}
			psh(0, arr[i].sc, arr[i].fr, b);
		}
		ans.push_back(arr[st].sc);
		done: st = ed; trie.clear();
	}
	if (ans.size() < 2){ cout << -1; }
	else{
		cout << ans.size() << endl;
		for (ll x : ans){ cout << x << ' '; }
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