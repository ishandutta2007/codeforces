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
	long double l = nxt();
	int v1 = nxt(), v2 = nxt(), k = nxt();
	int m = (n - 1) / k;
	cout << setprecision(10) << fixed;
	long double s = (l * (v1 + v2)) / (2ll * v1 * m + v1 + v2);
	cout << s / v2 + (l - s) / v1 << "\n";

	return 0;
}