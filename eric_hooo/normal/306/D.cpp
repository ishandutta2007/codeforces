#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <double, double> pdd;

const double pi = 3.1415926535897932384626433832795;
const double EPS = 1e-6;

pdd operator + (const pdd &A, const pdd &B) {return mp(A.fi + B.fi, A.se + B.se);}

pdd operator - (const pdd &A, const pdd &B) {return mp(A.fi - B.fi, A.se - B.se);}

pdd operator * (const pdd &A, const double &x) {return mp(A.fi * x, A.se * x);}

pdd a[110];
double coef[110];
int n;

bool Check() {
	pdd sum = mp(0, 0); for (int i = 0; i < n; i++) sum = sum + a[i] * coef[i];
	if (fabs(sum.fi) > EPS || fabs(sum.se) > EPS) return 0;
	for (int i = 0; i < n; i++) if (coef[i] < 2) return 0;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		if (fabs(coef[i] - coef[j]) < 1e-2) return 0;
	}
	return 1;
}

int main() {
	srand((int)time(NULL));
	cin >> n;
	if (n <= 4) {
		cout << "No solution" << endl;
		return 0;
	}
	double Angle = pi - 2 * pi / n;
	for (int i = 0; i < n; i++) {
		a[i] = mp(cos(2 * pi / n * i), sin(2 * pi / n * i));
	}
	BEG:;
	pdd sum = mp(0, 0);
	for (int i = 2; i < n; i++) coef[i] = 100 + (rand() % 20000 - 10000) * 0.001, sum = sum + a[i] * coef[i];
	coef[1] = -sum.se / a[1].se, sum = sum + a[1] * coef[1];
	if (coef[1] < 0) goto BEG;
	assert(fabs(sum.se) < EPS);
	coef[0] = -sum.fi, sum = sum + a[0] * coef[0];
	if (coef[0] < 0) goto BEG;
	if (!Check()) goto BEG;
	pdd cur = mp(0, 0); cout << fixed << setprecision(10) << cur.fi << " " << cur.se << endl;
	for (int i = 0; i + 1 < n; i++) {
		cur = cur + a[i] * coef[i];
		cout << fixed << setprecision(10) << cur.fi << " " << cur.se << endl;
	}
	return 0;
}