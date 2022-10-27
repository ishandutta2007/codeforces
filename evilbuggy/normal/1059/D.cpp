#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;
double x[maxN], y[maxN], dist2[maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int neg = 0;
	for(int i = 0; i < n; i++){
		int xx, yy;
		cin >> xx >> yy;
		if(yy < 0){
			neg++;
			yy = -yy;
		}
		x[i] = xx;
		y[i] = yy;
		dist2[i] = x[i]*x[i] + y[i]*y[i];
	}
	if(neg != 0 && neg != n){
		cout << -1 << '\n';
		return 0;
	}
	double lo = -1e8;
	double hi = +1e8;
	for(int iter = 0; iter < 100; iter++){
		double m1 = (lo + lo + hi)/3;
		double m2 = (lo + hi + hi)/3;
		double m1square = m1*m1;
		double m2square = m2*m2;
		double radius1 = 0.0;
		double radius2 = 0.0;
		for(int i = 0; i < n; i++){
			radius1 = max(radius1, (dist2[i] + m1square - 2*x[i]*m1)/(2*y[i]));
			radius2 = max(radius2, (dist2[i] + m2square - 2*x[i]*m2)/(2*y[i]));
		}
		if(radius1 > radius2){
			lo = m1;
		}else{
			hi = m2;
		}
	}
	double radius = 0.0;
	double losquare = lo*lo;
	for(int i = 0; i < n; i++){
		radius = max(radius, (dist2[i] + losquare - 2*x[i]*lo)/(2*y[i]));
	}
	cout << setprecision(20) << radius << '\n';

	return 0;
}