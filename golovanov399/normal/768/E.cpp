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
/*
const int N = 60;
map<pair<int, long long>, int> M;

int cur;
long long tmp;
int cursum;

void ololo() {
	vector<int> pr;
	for (int i = 1; i <= cur; ++i) {
		if (tmp & (1ll << i)) {
			continue;
		}
		long long tt = tmp | (1ll << i);
		tt &= (1ll << (cur - i + 1)) - 1;
		pr.push_back(M[{cur - i, tt}]);
	}
	sort(all(pr));
	pr.resize(unique(all(pr)) - pr.begin());
	int i = 0;
	while (i < (int)pr.size() && pr[i] == i) {
		++i;
	}
	M[{cur, tmp}] = i;
}

void rec(int k) {
	if (k > cur || cursum + k > N) {
		ololo();
		return;
	}
	cursum += k;
	tmp ^= (1ll << k);
	rec(k + 1);
	tmp ^= (1ll << k);
	cursum -= k;
	rec(k + 1);
}
*/
int main(){
	int n = nxt();
	int x = 0;
	for (int i = 0; i < n; ++i) {
		int q = nxt();
		int j = 0;
		while ((j + 1) * (j + 2) / 2 <= q) {
			++j;
		}
		x ^= j;
	}

	puts(x ? "NO" : "YES");

	return 0;
}