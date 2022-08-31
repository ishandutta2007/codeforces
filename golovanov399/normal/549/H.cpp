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

bool ok(double l1, double r1, double l2, double r2){
	return !(r1 < l2 || r2 < l1);
}

int main(){

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	double l = 0, r = 1e9;
	int it = 100;
	vector<double> q(4), w(4);
	while (it--){
		double m = (l + r) / 2;
		q = vector<double>({(a - m) * (d - m), (a - m) * (d + m), (a + m) * (d - m), (a + m) * (d + m)});
		w = vector<double>({(b - m) * (c - m), (b - m) * (c + m), (b + m) * (c - m), (b + m) * (c + m)});
		sort(all(q));
		sort(all(w));
		if (ok(q[0], q[3], w[0], w[3]))
			r = m;
		else
			l = m;
	}
	cout << setprecision(10) << fixed << l << "\n";

	return 0;
}