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

bool is_prime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(){

	int n = nxt();
	if (n == 1) {
		cout << "1\n1\n";
		return 0;
	} else if (n == 2) {
		cout << "1\n1 1\n";
		return 0;
	}

	printf("%d\n", 2);
	for (int i = 0; i < n; ++i) {
		printf("%d ", is_prime(i + 2) ? 1 : 2);
	}
	printf("\n");

	return 0;
}