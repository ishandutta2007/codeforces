#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

vector<int> zFunction(const string& s) {
    int n = s.length();

    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = max(min(z[i - l], r - i), 0);

        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    
    if (n)
        z[0] = n;

    return z;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	auto z = zFunction(t);
	int cnt[2] = {0, 0};
	for (char c : s) {
		cnt[c - '0'] += 1;
	}

	int mn = (int)t.size();
	for (int i = 1; i < (int)t.size(); ++i) {
		if (z[i] == (int)t.size() - i) {
			mn = i;
			break;
		}
	}

	int pre_cnt[2] = {0, 0};
	int t_cnt[2] = {0, 0};
	for (char c : t) {
		t_cnt[c - '0'] += 1;
	}
	for (int i = 0; i < mn; ++i) {
		pre_cnt[t[i] - '0'] += 1;
	}

	if (t_cnt[0] > cnt[0] || t_cnt[1] > cnt[1]) {
		cout << s << "\n";
		return 0;
	}

	string res = t;
	while (t_cnt[0] + pre_cnt[0] <= cnt[0] && t_cnt[1] + pre_cnt[1] <= cnt[1]) {
		res += t.substr((int)t.size() - mn);
		t_cnt[0] += pre_cnt[0];
		t_cnt[1] += pre_cnt[1];
	}
	while (t_cnt[0] < cnt[0]) {
		res += '0';
		t_cnt[0] += 1;
	}
	while (t_cnt[1] < cnt[1]) {
		res += '1';
		t_cnt[1] += 1;
	}
	cout << res << "\n";

	return 0;
}