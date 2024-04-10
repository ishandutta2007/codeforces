#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int ax, ay, bx, by, tx, ty, x[N], y[N];

inline double dist(double x, double y){
	return sqrt(x*x + y*y);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> tx >> ty;
	int n; cin >> n;
	double sum = 0.0;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		sum += 2*dist(tx - x[i], ty - y[i]);
	}
	pair<double, int> mna1 = {1e18, -1};
	pair<double, int> mna2 = {1e18, -1};
	for(int i = 0; i < n; i++){
		double tmp = dist(ax - x[i], ay - y[i]) - dist(tx - x[i], ty - y[i]);
		if(tmp < mna1.first){
			mna2 = mna1;
			mna1 = {tmp, i};
		}else if(tmp < mna2.first){
			mna2 = {tmp, i};
		}
	}
	pair<double, int> mnb1 = {1e18, -1};
	pair<double, int> mnb2 = {1e18, -1};
	for(int i = 0; i < n; i++){
		double tmp = dist(bx - x[i], by - y[i]) - dist(tx - x[i], ty - y[i]);
		if(tmp < mnb1.first){
			mnb2 = mnb1;
			mnb1 = {tmp, i};
		}else if(tmp < mnb2.first){
			mnb2 = {tmp, i};
		}
	}
	double ans = 1e18;
	ans = min(ans, sum + mna1.first);
	ans = min(ans, sum + mnb1.first);
	for(auto x : {mna1, mna2}){
		for(auto y : {mnb1, mnb2}){
			if(x.second == -1 || y.second == -1 || x.second == y.second)continue;
			ans = min(ans, sum + x.first + y.first);
		}
	}
	cout << fixed << setprecision(12) << ans << '\n';

	return 0;
}