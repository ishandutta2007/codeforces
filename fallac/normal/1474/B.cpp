#include <bits/stdc++.h>
using namespace std;
#define MAX 31000
#define MOD 1000000007
#define pb push_back
#define ln '\n'
int arr[MAX];
void f() {
	int i, j;
	for (i = 2; i <= 30000; i++) {
		if (arr[i]) continue;
		for (j = 2 * i; j <= 30000; j += i) {
			arr[j] = 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	f();
	int T;
	cin >> T;
	while (T-- > 0) {
		int d;
		cin >> d;
		int i = d;
		int p1, p2;
		while (arr[++i]);
		p1 = i;
		i += d;
		i--;
		while (arr[++i]);
		p2 = i;
		cout << p1 * p2 << ln;
	}
	return 0;
}