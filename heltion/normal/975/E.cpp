#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 12000;
constexpr double PI = acos(-1);
struct point{
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y){}
}p[maxn], center, icenter;
point operator + (const point &a, const point &b){
	return point(a.x + b.x, a.y + b.y);
}
point operator += (point &a, const point &b){
	return point(a.x += b.x, a.y += b.y);
}
point operator - (const point &a, const point &b){
	return point(a.x - b.x, a.y - b.y);
}
point operator * (const point &a, const double &b){
	return point(a.x * b, a.y * b);
}
point operator / (const point &a, const double &b){
	return point(a.x / b, a.y / b);
}
point operator /= (point &a, const double &b){
	return point(a.x /= b, a.y /= b);
}
double cross(const point &a, const point &b){
	return a.x * b.y - a.y * b.x;
}
point rotate(const point &a, const double &b){
	return point(a.x * cos(b) - a.y * sin(b), a.x * sin(b) + a.y * cos(b));
}
int main(){
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i += 1) cin >> p[i].x >> p[i].y;
	double area = 0;
	for(int i = 2; i + 1 <= n; i += 1){
		point tcenter = (p[1] + p[i] + p[i + 1]) / 3.0;
		double tarea = abs(cross(p[i] - p[1], p[i + 1] - p[1]));
		center += tcenter * tarea;
		area += tarea;
	}
	icenter = center /= area;
	int u = 1, v = 2;
	double angle = 0;
	while(q --){
		int op;
		cin >> op;
		if(op == 1){
			int f, t, pi;
			cin >> f >> t;
			pi = f ^ u ^ v;
			point pivot = rotate(p[pi] - icenter, angle) + center;
			double xx = atan2(center.y - pivot.y, center.x - pivot.x);
			center = rotate(center - pivot, 1.5 * PI - xx) + pivot;
			double yy = atan2(p[pi].y - icenter.y, p[pi].x - icenter.x);
			angle = .5 * PI - yy;
			u = pi, v = t;
		}
		else{
			int v;
			cin >> v;
			point pv = rotate(p[v] - icenter, angle) + center;
			cout << setprecision(11) << pv.x << " " << pv.y << "\n";
		}
	}
}