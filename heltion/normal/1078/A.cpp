#include<bits/stdc++.h>
using namespace std;
double x[4], y[4];
int main(){
	double a, b, c;
	cin >> a >> b >> c >> x[0] >> y[0] >> x[1] >> y[1];
	double ans = abs(x[0] - x[1]) + abs(y[0] - y[1]);
	for(int i = 0; i < 2; i += 1)
		for(int j = 0; j < 2; j += 1){
			double L = 0, R = 0;
			if(i == 0){
				if(a == 0) continue;
				y[2] = y[0];
				x[2] = (- c - b * y[2]) / a;
				L = abs(x[2] - x[0]);
			}
			
			if(i == 1){
				if(b == 0) continue;
				x[2] = x[0];
				y[2] = (- c - a * x[2]) / b;
				L = abs(y[2] - y[0]);
			}
			
			if(j == 0){
				if(a == 0) continue;
				y[3] = y[1];
				x[3] = (- c - b * y[3]) / a;
				R = abs(x[3] - x[1]);
			}
			
			if(j == 1){
				if(b == 0) continue;
				x[3] = x[1];
				y[3] = (- c - a * x[3]) / b;
				R = abs(y[3] - y[1]);
			}
			//cout << i << " " << j << " "
			//	<< x[2] << " " << y[2] << " "
			//	<< x[3] << " " << y[3] << " " <<endl;
			ans = min(ans, L + R + hypot(x[2] - x[3], y[2] - y[3]));
		}
	cout << setprecision(11) << ans;
}