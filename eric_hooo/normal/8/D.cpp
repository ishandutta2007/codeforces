#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;
const double pi = 3.1415926535897932384626433832795;

struct Point {
	double x, y;
	Point() {x = 0, y = 0;}
	Point(double a, double b) {x = a, y = b;}
	double len() const {return sqrt(x * x + y * y);}
	double dist(const Point &A) const {return (*this - A).len();}
	Point unit() const {return *this / len();}
	Point operator + (const Point &A) const {return Point(x + A.x, y + A.y);}
	Point operator - (const Point &A) const {return Point(x - A.x, y - A.y);}
	Point operator * (const double &A) const {return Point(x * A, y * A);}
	Point operator / (const double &A) const {return Point(x / A, y / A);}
	double operator * (const Point &A) const {return x * A.x + y * A.y;}
	double operator ^ (const Point &A) const {return x * A.y - y * A.x;}
};

double Rand() {
	if (RAND_MAX <= 32767) return (double)(rand() << 15 | rand()) / RAND_MAX / RAND_MAX;
	return (double)rand() / RAND_MAX;
}

int main() {
	srand((int)time(NULL));
	int t1, t2; cin >> t1 >> t2;
	Point A, B, C; cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	if (A.dist(C) + C.dist(B) - A.dist(B) - EPS <= t2) {
		cout << fixed << setprecision(10) << min(A.dist(B) + t2, A.dist(C) + C.dist(B) + t1) << endl;
		return 0;
	}
	double R2 = A.dist(B) + t2, R1 = A.dist(C) + t1;
	// (P - A) ^ 2 + (P - B) ^ 2 == R2
	// (P - A) ^ 2 + (P - C) ^ 2 == R1
	Point P = A;
	double T = 1000;
	auto GetVal = [&](Point P) -> double {
		return min(A.dist(B) + t2 - P.dist(B), A.dist(C) + t1 - P.dist(C));
	};
	while (T > 1e-8) {
		double x = Rand(), y = 1 - y;
		double the = x * 2 * pi;
		Point dir = Point(cos(the), sin(the)) * T;
		if (t2 == 0) dir = (B - P).unit() * T;
		if (t1 == 0) dir = (C - P).unit() * T;
		Point PP = P + dir;
		if (PP.dist(A) + PP.dist(B) - EPS <= R2 && PP.dist(A) + PP.dist(C) - EPS <= R1) {
			if (GetVal(PP) > GetVal(P)) P = PP;
		}
		T = T * 0.99999;
	}
	// cerr << "               P:" << P.x << " " << P.y << endl;
	// cerr << "          P:" << P.dist(A) + P.dist(B) << " " << R2 << " : " << P.dist(A) + P.dist(C) << " " << R1 << endl;
	cout << fixed << setprecision(10) << min(A.dist(B) + t2 - P.dist(B), A.dist(C) + t1 - P.dist(C)) << endl;
	return 0;
}