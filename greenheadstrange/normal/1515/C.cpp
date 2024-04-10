//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {return x < y ? x = y, true : false;}
template <typename T> bool chkmin(T &x, T y) {return x > y ? x = y, true : false;}

using namespace std;


void solve() {
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);
	set<pair<ll, int>> tower;
	for (int i = 0; i < m; i++) {
		tower.insert({0ll, i + 1});
	}
	puts("YES");
	for (int i = 0; i < n; i++) {
		auto s = *tower.begin();
		tower.erase(tower.begin());
		int h;
		scanf("%d", &h);
		printf("%d\n", s.second);
		s.first += h;
		tower.insert(s);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		solve();
	}
}