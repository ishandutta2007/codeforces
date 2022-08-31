#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

// void solve() {
// 	//
// }

int main() {
	cout << ((nxt() - 1) % 9) + 1 << "\n";

	return 0;
}