#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	string s;
	cin >> s;
	char c = *min_element(all(s));
	for (int i = 0; i < (int)s.length(); ++i) {
		bool f1 = (s[i] == c);
		bool f2 = ((i + 1) < (int)s.length() && s[i + 1] == c);
		cout << (int)(f1 != f2) << " ";
	}
	cout << "\n";

	return 0;
}