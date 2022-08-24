#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 1111111;
int erat[N];
int phi[N];

map<long long, vector<pair<long long, int>>> M;

vector<pair<long long, int>> factor(long long n) {
	if (M.count(n)) {
		return M[n];
	}
	vector<pair<long long, int>>& a = M[n];
	long long i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			a.push_back({i, 0});
			while (n % i == 0) {
				a.back().second += 1;
				n /= i;
			}
		}
		++i;
	}
	if (n > 1) {
		a.push_back({n, 1});
	}

	return a;
}

int main(){

	erat[1] = phi[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			if (1.0 * i * i < N + N) {
				for (int j = i * i; j < N; j += i) {
					if (erat[j] == 0) {
						erat[j] = i;
					}
				}
			}
		}
		if (erat[i / erat[i]] == erat[i]) {
			phi[i] = phi[i / erat[i]] * erat[i];
		} else {
			phi[i] = phi[i / erat[i]] * (erat[i] - 1);
		}
	}

	long long n, k;
	cin >> n >> k;
	auto a = factor(n);

	k = (k + 1) / 2;
	for (int i = 0; i < k; ++i) {
		if (n == 1) {
			break;
		}
		if (n < N) {
			n = phi[n];
			continue;
		}
		vector<pair<long long, int>> b;
		for (auto p : a) {
			if (p.second > 1) {
				b.push_back({p.first, p.second - 1});
			}
			n = n / p.first * (p.first - 1);
			vector<pair<long long, int>> c = factor(p.first - 1);
			b.insert(b.end(), all(c));
		}
		sort(all(b));
		a.clear();
		for (auto p : b) {
			if (!a.empty() && a.back().first == p.first) {
				a.back().second += p.second;
			} else {
				a.push_back(p);
			}
		}
	}

	cout << n % 1000000007 << "\n";

	return 0;
}