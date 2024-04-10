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

void panic() {
	puts("-1");
	exit(0);
}

int main(){

	int k = nxt(), a = nxt(), b = nxt();
	if (a < k && b < k) {
		panic();
	}
	if (a < b) {
		swap(a, b);
	}
	if (b < k) {
		if (a % k == 0) {
			cout << a / k << "\n";
			return 0;
		} else {
			panic();
		}
	}
	cout << a / k + b / k << "\n";

	return 0;
}