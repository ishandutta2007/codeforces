#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 100 * 1000 + 10, mod = 1e9 + 7, inv2 = 500000004;
int n, q;
string t;
string s[21];
int p[3000 * 1000 + 10];
bool ok_suf[1000 * 1000 + 10], ok_pref[1000 * 1000 + 10];
int mx = 20;
int cnt[nax][26], ile[26], pot[nax], inv[nax];

void kmp(string &s2) {
	for(int i = 2; i <= (int)s2.size(); ++i) {
		int w = p[i - 1];
		while(w > 0 && s2[w] != s2[i - 1]) w = p[w];
		if(s2[w] == s2[i - 1]) w++;
		p[i] = w;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> s[0] >> t;
	mx = n;
	for(int i = 1; i <= n;++i) {
		s[i] = s[i - 1] + t[i - 1] + s[i - 1];
		//remember to change!
		if((int)s[i].size() >= 1000*1000) {
			mx = i;
			break;
		}
	}
	//cout << mx << " ";
	pot[0] = 1; inv[0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 26; ++j) cnt[i][j] = (2 * cnt[i - 1][j]) % mod;
		cnt[i][t[i - 1]-'a']++;
		cnt[i][t[i-1]-'a']%= mod;
		pot[i] = (pot[i-1]+pot[i-1]) % mod;
		inv[i] = ((ll)inv[i - 1] * inv2) % mod;
	}
	while(q--) {
		int k;
		string w;
		cin >> k >> w;
		int b = mx;
		for(int i = 1; i <= (int)w.size(); ++i) {
			ok_suf[i] = ok_pref[i] =  0;
		}
		for(int i = 0; i < 26; ++i) ile[i] = 0;
		while(b > 0 && (int)s[b - 1].size() >= (int)w.size()) {
			b--;
		}
		if(b > k || (int)s[b].size() < (int)w.size()) {
			cout << "0\n";
			continue;
		}
		string tmp = s[b] + '#' + w;
		kmp(tmp);
		int x = (int)tmp.size();
		while(p[x] != 0) {
			ok_suf[(int)w.size()-p[x]+1] = 1;
			x = p[x];
		}
		tmp = w + '#' + s[b];
		kmp(tmp);
		x = (int)tmp.size();
		while(p[x] != 0) {
			ok_pref[p[x]] = 1;
			x = p[x];
		}
		int f = 0;
		for(int i = (int)w.size() + 1; i <= (int)tmp.size(); ++i) {
			if(p[i] == (int)w.size()) f++;
		}
		ok_pref[0] = ok_suf[(int)w.size() + 1] = 1;
		//for(int i = 1; i <= (int)w.size(); ++i) {
			//cout << i << " " << ok_pref[i] << " " << ok_suf[i] << "\n";
		//}
		for(int i = 1; i <= (int)w.size(); ++i) {
			if(ok_pref[i - 1] && ok_suf[i + 1]) {
				ile[w[i - 1] - 'a']++;
			}
		}
		int res = 0;
		//cout << cnt[k][1] - cnt[b][1] << " ";
		for(int i = 0; i < 26; ++i) {
			res = (res + (ll)ile[i] * (cnt[k][i] - (((ll)cnt[b][i] * pot[k - b]) % mod))) % mod;
			if(res < 0) res += mod;
		}
		//res = ((ll)res * inv[b]) % mod;
		res = (res + (ll)f * pot[k - b]) % mod;
		//cout << b << " " << k << " " << f << "\n";
		cout << res << "\n";
	}
		
		
}