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

int sqr(int x) {
	return x * x;
}

int main() {
	cout << 2 - sqr(nxt()) << "\n";

	return 0;
}