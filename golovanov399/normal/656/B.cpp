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

int gcd(int x, int y){
	while (y){
		x %= y;
		swap(x, y);
	}
	return x;
}

int lcm(int x, int y){
	return x * y / gcd(x, y);
}

pair<int, int> crt(pair<int, int> a, pair<int, int> b){
	int l = lcm(a.x, b.x);
	for (int i = 0; i < l / a.x; i++){
		if ((a.y + a.x * i) % b.x == b.y){
			return {l, a.y + a.x * i};
		}
	}
	return {-1, -1};
}

int main(){

	int n = nxt();
	vector<int> a(n), b(n);
	for (itn i = 0; i < n; i++)
		a[i] = nxt();
	for (int i = 0; i < n; i++)
		b[i] = nxt();

	double ans = 0;

	for (int mask = 0; mask < (1 << n); mask++){
		pair<int, int> p = {1, 0};
		for (int i = 0; i < n && p.x > -1; i++){
			if (mask & (1 << i))
				p = crt(p, {a[i], b[i]});
		}
		double tmp = p.x > -1 ? 1.0 / p.x : 0;
		if (__builtin_parity(mask) == 0)
			ans += tmp;
		else
			ans -= tmp;
	}

	cout << setprecision(10) << fixed;
	cout << 1 - ans << "\n";

	return 0;
}