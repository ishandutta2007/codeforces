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

int main(){

	string s;
	cin >> s;

	vector<int> cnt(256);
	for (char c : s) {
		cnt[c] += 1;
	}
	string t = "Bulbasaur";
	vector<int> cn(256);
	for (char c : t) {
		cn[c] += 1;
	}
	int ans = 1e9;
	for (int i = 0; i < 256; ++i) {
		if (cn[i] == 0) {
			continue;
		}
		ans = min(ans, cnt[i] / cn[i]);
	}

	printf("%d\n", ans);

	return 0;
}