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

	long long n;
	cin >> n;
	long long x = 1, y = 2;
	int ans = 0;
	while (y <= n) {
		ans += 1;
		x += y;
		swap(x, y);
	}

	printf("%d\n", ans);

	return 0;
}