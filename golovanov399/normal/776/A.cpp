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

	string s, t;
	cin >> s >> t;
	int n = nxt();
	cout << s << " " << t << "\n";
	for (int i = 0; i < n; ++i) {
		string q;
		cin >> q;
		string& w = (s == q) ? s : t;
		cin >> w;
		cout << s << " " << t << "\n";
	}

	return 0;
}