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

const int N = 222222;
int a[N];
int n;

double check(double x){
	double mx = -1e9, mn = 1e9;
	double curmx = mx, curmn = mn;
	for (int i = 0; i < n; i++){
		mn = min(mn, 0.0) + a[i] - x;
		curmn = min(curmn, mn);
		mx = max(mx, 0.0) + a[i] - x;
		curmx = max(curmx, mx);
	}
	return max(fabs(curmn), fabs(curmx));
}

int main(){

	n = nxt();
	for (int i = 0; i < n; i++)
		a[i] = nxt();

	vector<int> pref(n + 1);
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + a[i];

	int magic = 500000;

	double l = -10000, r = 10000;
	int it = 100;
	while (--it){
		double m1 = (l * 2 + r) / 3, m2 = (l + 2 * r) / 3;
		double res1 = check(m1), res2 = check(m2);
		if (res1 > res2)
			l = m1;
		else
			r = m2;
	}
	cout << setprecision(10) << fixed;

	cout << check((l + r) / 2) << "\n";

	return 0;
}