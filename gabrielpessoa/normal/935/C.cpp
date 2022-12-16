#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;

const int SIZE  = 1E5+5;
const int MOD = 1E9+9;
const int DELTA = 1E5+2;
const double PI = atan(1)*4;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;
const double INFF = 1e100;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  return os << "(" << p.x << "," << p.y << ")"; 
}


int main() {
	double r, x1, y1, x2, y2;
	cout << fixed << setprecision(16);
	cin >> r >> x1 >> y1 >> x2 >> y2;
	PT center = PT(x1, y1);
	PT fafa = PT(x2, y2);
	double distancia = dist2(center, fafa);
	if(distancia > r * r) {
		cout << x1 << ' ' << y1 << ' ' << r << '\n';
	} else if(distancia > EPS) {
		distancia = sqrt(distancia);
		PT newCenter = fafa + ((center - fafa)/distancia * ((distancia + r)/2));
		double newR = ((distancia + r)/ 2);
		cout << newCenter.x << ' ' << newCenter.y << ' ' << newR << '\n';
	} else {
		PT newCenter = fafa + PT(1, 0) * (r / 2);
		double newR = r/2;		
		cout << newCenter.x << ' ' << newCenter.y << ' ' << newR << '\n';
	}
	return 0;
}