#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	cout.sync_with_stdio(0);

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			cout << 2 << "\n";
		} else {
			cout << 1ll * i * (i + 1) * (i + 1) - i + 1 << "\n";
		}
	}

	return 0;
}