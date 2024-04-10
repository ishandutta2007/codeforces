#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

const int mod = 1000000007;

int main(){

	cin.sync_with_stdio(0);

	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	int m = s.length();

	vector<int> pr(k, -1);
	vector<long long> cnt(m + n);
	vector<long long> S(m + n);
	long long qw = 0;

	for (int i = 0; i < m; i++){
		int c = s[i] - 'a';
		if (pr[c] == -1){
			cnt[i] += qw;
		} else {
			cnt[i] += qw - S[pr[c]] + mod;
		}
		if (pr[c] > -1)
			cnt[i] += cnt[pr[c]];
		else
			cnt[i] += 1;

		cnt[i] %= mod;
		S[i] = (qw + cnt[i]) % mod;
		pr[c] = i;
		qw = S[i];
	}

	// cerr << (S[m - 1] + 1) % mod << "\n";

	vector<int> qq;
	int of;

	for (int i = m; i < m + n; i++){
		int c;
		if (qq.size() < k)
			c = min_element(all(pr)) - pr.begin();
		else
			c = qq[(i - of) % k];
		if (pr[c] == -1){
			cnt[i] += qw;
		} else {
			cnt[i] += qw - S[pr[c]] + mod;
		}
		if (pr[c] > -1)
			cnt[i] += cnt[pr[c]];
		else
			cnt[i] += 1;

		cnt[i] %= mod;
		S[i] = (qw + cnt[i]) % mod;
		pr[c] = i;
		qw = S[i];

		if (qq.size() < k){
			qq.push_back(c);
			if (qq.size() == k)
				of = i + 1;
		}
	}

	// for (auto x : cnt)
	// 	cerr << x << " ";
	// cerr << "\n";

	cout << (S[n + m - 1] + 1) % mod << "\n";

	return 0;
}