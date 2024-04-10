#include <bits/stdc++.h>

using namespace std;

double w_, b_;
double p, d, dp[1010][1010][2];

double solve(int w, int b, int t) {
	if(w + b == 0) return t;
	if(dp[w][b][t] != -1) return dp[w][b][t];
	
	double x;
	
	if(!t) {
		x = w / (w + b + 0.0);
		if(b > 0) x += (1.0 - x) * (1.0 - solve(w, b-1, !t));
	} else {
		x = w / (w + b + 0.0);
		double p = x;
		if(w + b > 1) {
			if(b > 1) x += (1.0 - p) * ((b - 1.0) / (w + b - 1.0)) * (1.0 - solve(w, b-2, !t));
			if(w > 0 && b > 0) x += (1.0 - p) * (w / (w + b - 1.0)) * (1.0 - solve(w-1, b-1, !t));
		}
		
		if(w == 0 and b == 1) x = 1;
	}
	
	return dp[w][b][t] = x;
}

int main() {
	scanf("%lf %lf", &w_, &b_);
	
	if(w_ + b_ == 0) {
		printf("0\n");
		return 0;
	}
	
	for(int i=0;i<1010; i++)
		for(int j=0;j<1010;j++)
			dp[i][j][0] = dp[i][j][1] = -1;
			
	printf("%.9f\n", solve(w_, b_, 0));
	
	return 0;
}