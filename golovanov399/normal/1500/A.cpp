#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void A() {
	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = {nxt(), i + 1};
	}
	sort(all(a));

	constexpr int N = 5e6 + 10;
	vector<pair<int, int>> cur(N, {-1, -1});
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			int x = a[i].first + a[j].first;
			if (cur[x].first > -1 && cur[x].first != a[i].second && cur[x].second != a[i].second && cur[x].first != a[j].second && cur[x].second != a[j].second) {
				cout << "YES\n" << cur[x].first << " " << cur[x].second << " " << a[i].second << " " << a[j].second << "\n";
				return;
			} else if (cur[x].first == -1) {
				cur[x] = {a[i].second, a[j].second};
			}
		}
	}
	cout << "NO\n";
}

int inv(int a, int b) {
	return a == 1 ? 1 : b - 1ll * inv(b % a, a) * b / a % b;
}

void B() {
	long long k;
	int n = nxt(), m = nxt();
	cin >> k;
	vector<int> pos_fst(n + m + 2, -1);
	vector<int> pos_snd(n + m + 2, -1);
	for (int i = 0; i < n; ++i) {
		pos_fst[nxt()] = i;
	}
	for (int i = 0; i < m; ++i) {
		pos_snd[nxt()] = i;
	}

	long long full_cycle = lcm<long long>(n, m);
	int g = gcd(n, m);
	const int sz = pos_fst.size();
	vector<long long> positions;
	long long only_first = inv(m / g, n / g) % (n / g) * (m / g);
	long long only_second = inv(n / g, m / g) % (m / g) * (n / g);
	for (int i = 0; i < sz; ++i) {
		if (pos_fst[i] > -1 && pos_snd[i] > -1 && pos_fst[i] % g == pos_snd[i] % g) {
			positions.push_back((pos_fst[i] / g * only_first + pos_snd[i] / g * only_second) % (full_cycle / g) * g + pos_fst[i] % g);
		}
	}
	sort(all(positions));
	const int coinc = positions.size();
	long long offset = (k - 1) / (full_cycle - coinc) * full_cycle;
	k -= (k - 1) / (full_cycle - coinc) * (full_cycle - coinc);
	long long l = 0, r = full_cycle;
	while (r > l + 1) {
		long long m = (l + r) / 2;
		if (m - (upper_bound(all(positions), m) - positions.begin()) >= k) {
			r = m;
		} else {
			l = m;
		}
	}
	cout << offset + r << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	A();

	return 0;
}