#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 500500;

struct pt {
	ld x, y;
	pt(): x(0), y(0) {}
	pt(ld _x, ld _y) {
		x = _x, y = _y;
	}
};

bool eq(ld a, ld b) {
	return (fabs(a - b) < eps);
}

bool eq(pt a, pt b) {
	return eq(a.x, b.x) && eq(a.y, b.y);
}

pt read_pt() {
	ld a, b;
	cin >> a >> b;
	return pt(a, b);
}

bool operator==(pt a, pt b) {
	return a.x == b.x && a.y == b.y;
}

inline bool operator<(pt a, pt b) {
	return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
}

pt operator-(pt p1, pt p2) {
	return pt(p1.x - p2.x, p1.y - p2.y);
}

pt operator+(pt p1, pt p2) {
	return pt(p1.x + p2.x, p1.y + p2.y);
}

pt operator*(pt a, ld b) {
	return pt(a.x * b, a.y * b);
}

pt operator/(pt a, ld b) {
	return pt(a.x / b, a.y / b);
}

ld len(pt a) {
	return sqrt(.0 + a.x * a.x + a.y * a.y);
}

ld dist(pt p1, pt p2) {
	return len(p1 - p2);
}

pt A, B;
pt V1, V2;
ld speed, change;

bool ok(ld T) {
	ld TT = T;
	pt cur = A;
	if (T >= change) {
		cur = cur + V2 * (T - change);
		T = change;	
	}
	cur = cur + V1 * T;
	return dist(cur, B) <= speed * TT;	
}

ld bins(ld L, ld R) {
	ld M;
	forn(i, 10000) {
		M = (L + R) / 2;
		if (ok(M))
			R = M;
		else
			L = M;
	}             
	return L;
}

int main() {

	A = read_pt();
	B = read_pt();
	cin >> speed >> change;
	V1 = read_pt();
	V2 = read_pt();
		
	ld ans;
	if (ok(change))
		ans = bins(0, change);
	else
		ans = bins(change, 1E100);
	
	cout.precision(30);
	cout << ans;
	
	return 0;
}