#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int a[3];
	for (int i = 0; i < 3; ++i) {
		a[i] = nxt();
	}
	sort(a, a + 3);
	if (a[0] == 1 ||
		a[0] == 2 && a[1] == 2 ||
		a[0] == 2 && a[1] == 4 && a[2] == 4 ||
		a[0] == 3 && a[2] == 3) {
		puts("YES");
	} else {
		puts("NO");
	}
	
	return 0;
}