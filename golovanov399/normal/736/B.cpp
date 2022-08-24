#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
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
	if (is_prime(n)) {
		printf("%d\n", 1);
	} else if (n % 2 == 0) {
		printf("%d\n", 2);
	} else if (is_prime(n - 2)) {
		printf("%d\n", 2);
	} else {
		printf("%d\n", 3);
	}

	return 0;
}