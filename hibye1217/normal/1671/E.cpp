#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;

const ll mod = 998244353;
int n, m; string s;
pi2 nxt[262150];
ll dp[262150]; bool chk[262150];

string dfs(int now){
	if (now*2 > n){ chk[now] = 1; return string(1, s[now]); }
	string s1 = dfs(nxt[now].fr); string s2 = dfs(nxt[now].sc);
	//cout << "CMP " << now << " | " << nxt[now].fr << ' ' << s1 << " : " << nxt[now].sc << ' ' << s2 << endl;
	if (s1 > s2){ swap(s1, s2); swap(nxt[now].fr, nxt[now].sc); }
	chk[now] = s1 == s2;
	return s[now] + s1 + s2;
}

void dpf(int now){
	if (now*2 > n){ dp[now] = 1; return; }
	dpf(nxt[now].fr); dpf(nxt[now].sc);
	ll v1 = dp[nxt[now].fr], v2 = dp[nxt[now].sc];
	if (chk[now]){ dp[now] = v1*v2 % mod; }
	else{ dp[now] = v1*v2*2 % mod; }
	//cout << "DP " << now << " = " << dp[now] << endl;
}

void Main(){
	cin >> m >> s; n = (1<<m) - 1; s = " " + s;
	for (int i = 1; i*2+1 <= n; i++){ nxt[i] = {i<<1, i<<1|1}; }
	dfs(1); dpf(1); cout << dp[1];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}