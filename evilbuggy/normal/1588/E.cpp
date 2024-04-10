#include <bits/stdc++.h>
using namespace std;

const int maxN = 3005;
const double eps = 1e-9;
const double PI = acos(-1.0);

int N, R, X[maxN], Y[maxN], chk[maxN][maxN];

inline long long dist2(long long x, long long y){
	return x*x + y*y;
}

inline double dist(double x, double y){
	return sqrt(x*x + y*y);
}

inline double getAngle(int x, int y){
	double ret = atan2(y, x);
	if(ret < -eps)ret += 2*PI;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> R;
	for(int i = 0; i < N; i++){
		cin >> X[i] >> Y[i];
	}
	int ans = 0;
	memset(chk, 0, sizeof(chk));
	for(int i = 0; i < N; i++){
		array<double, 2> range1({0.0, 2*PI});
		array<double, 2> range2({2*PI, 0.0});

		for(int j = 0; j < N; j++){
			if(dist2(X[j] - X[i], Y[j] - Y[i]) <= 1LL*R*R)continue;

			double angle = getAngle(X[j] - X[i], Y[j] - Y[i]);
			double theta = asin(R/dist(X[j] - X[i], Y[j] - Y[i]));

			double lo = angle - theta;
			double hi = angle + theta;

			if(hi > 2*PI + eps){
				lo -= 2*PI;
				hi -= 2*PI;
			}
			if(lo < eps){
				range2[0] = min(range2[0], hi);
				range2[1] = max(range2[1], lo + 2*PI);
			}else{
				range1[0] = max(range1[0], lo);
				range1[1] = min(range1[1], hi);
			}
		}

		for(int j = 0; j < N; j++){
			if(i == j)continue;
			double angle = getAngle(X[j] - X[i], Y[j] - Y[i]);
			bool flg = true;
			if(angle < range1[0] - eps || angle > range1[1] + eps){
				flg = false;
			}
			if(angle > range2[0] + eps && angle < range2[1] - eps){
				flg = false;
			}
			if(!flg){
				chk[i][j] = 1;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < i; j++){
			if(chk[i][j] == 0 && chk[j][i] == 0)ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}