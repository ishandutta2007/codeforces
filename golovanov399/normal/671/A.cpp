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

typedef pair<int, int> pii;

long double dist(pii p, pii q){
	return hypotl(p.x - q.x, p.y - q.y);
}

int main(){

	pii a, b, u;
	a.x = nxt();
	a.y = nxt();
	b.x = nxt();
	b.y = nxt();
	u.x = nxt();
	u.y = nxt();

	int n = nxt();
	vector<long double> A(n), B(n), U(n);
	for (int i = 0; i < n; i++){
		pii p;
		p.x = nxt();
		p.y = nxt();
		A[i] = dist(a, p);
		B[i] = dist(b, p);
		U[i] = dist(u, p);
	}

	if (n == 1){
		cout << setprecision(10) << fixed;
		cout << U[0] + min(A[0], B[0]) << "\n";
		return 0;
	}

	pair<long double, long double> _a(A[0] - U[0], A[1] - U[1]);
	pii posa(0, 1);
	if (_a.x < _a.y){
		swap(_a.x, _a.y);
		swap(posa.x, posa.y);
	}
	for (int i = 2; i < n; i++){
		if (A[i] - U[i] < _a.y){
			_a.x = _a.y;
			_a.y = A[i] - U[i];
			posa.x = posa.y;
			posa.y = i;
		} else
		if (A[i] - U[i] < _a.x){
			_a.x = A[i] - U[i];
			posa.x = i;
		}
	}

	pair<long double, long double> _b(B[0] - U[0], B[1] - U[1]);
	pii posb(0, 1);
	if (_b.x < _b.y){
		swap(_b.x, _b.y);
		swap(posb.x, posb.y);
	}
	for (int i = 2; i < n; i++){
		if (B[i] - U[i] < _b.y){
			_b.x = _b.y;
			_b.y = B[i] - U[i];
			posb.x = posb.y;
			posb.y = i;
		} else
		if (B[i] - U[i] < _b.x){
			_b.x = B[i] - U[i];
			posb.x = i;
		}
	}

	cout << setprecision(10) << fixed;
	long double res = min(_a.y, _b.y);
	if (posa.y != posb.y)
		res = min(res, _a.y + _b.y);
	else {
		res = min(res, _a.y + _b.x);
		res = min(res, _b.y + _a.x);
	}
	cout << 2 * accumulate(all(U), 0.0) + res << "\n";

	return 0;
}