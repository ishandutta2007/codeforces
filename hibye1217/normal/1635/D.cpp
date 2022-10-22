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

struct Node{ bool chk = 0; int nxt[2] = {-1, -1}; };
int arr[200020]; vector<int> v;
vector<Node> trie;

void upd(int pos, int val, int p){
	if (p < 0){ trie[pos].chk = 1; v.push_back(val); return; }
	int bit = 1<<p;
	if (trie[pos].chk == 1){
		int num = val % (bit*2);
		string s = "";
		int bb = bit;
		while (bb){
			if (bb & val){ s += '1'; }
			else{ s += '0'; }
			bb >>= 1;
		}
		bool chk = 1;
		int idx = 0, sl = s.size();
		while (idx < sl){
			if (s[idx] == '0'){
				if (idx+1 == sl){ chk = 0; break; }
				else{
					if (s[idx+1] == '0'){ idx += 2; }
					else{ chk = 0; break; }
				}
			}
			else{ idx += 1; }
		}
		if (chk){ return; }
	}
	int idx = (val & bit) ? 1 : 0;
	if (trie[pos].nxt[idx] == -1){
		trie[pos].nxt[idx] = trie.size();
		trie.push_back( Node() );
	}
	return upd(trie[pos].nxt[idx], val, p-1);
}

const ll mod = 1e9 + 7;
ll dp[200020];

void Main(){
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++){ cin >> arr[i]; }
	sort(arr+1, arr+n+1);
	trie.push_back( Node() );
	for (int i = 1; i <= n; i++){
		int p = 31;
		while (p >= 0){
			int bit = 1<<p;
			if (bit & arr[i]){ break; }
			else{ p -= 1; }
		}
		upd(0, arr[i], p);
	}
	int ptr = 0, vl = v.size();
	for (int i = 0; i <= m; i++){
		while (ptr < vl){
			int bit = 1<<i;
			if (v[ptr] < bit){ dp[i] += 1; ptr += 1; }
			else{ break; }
		}
		if (i >= 1){ dp[i] += dp[i-1]; dp[i] %= mod; }
		if (i >= 2){ dp[i] += dp[i-2]; dp[i] %= mod; }
		//cout << "DP " << i << ' ' << dp[i] << endl;
	}
	ll ans = 0;
	for (int i = 0; i <= m; i++){ ans += dp[i]; ans %= mod; }
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}