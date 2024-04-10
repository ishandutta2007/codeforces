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

int main(){

	int n = nxt();
	int h, m;
	scanf("%d:%d", &h, &m);

	if (n == 12) {
		if (h > 12) {
			h %= 10;
		}
		if (h == 0) {
			h += 10;
		}
	} else {
		if (h >= n) {
			h %= 10;
		}
	}

	if (m >= 60) {
		m %= 10;
	}

	cout << h / 10 << h % 10 << ":" << m / 10 << m % 10 << "\n";

	return 0;
}