#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-9;

long double a, b, c, ans;
long double X1, Y1, X2, Y2;

long double dist(long double X1, long double Y1, long double X2, long double Y2){
	return sqrt((X1 - X2)*(X1 - X2) + (Y1 - Y2)*(Y1 - Y2));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b >> c;
	cin >> X1 >> Y1 >> X2 >> Y2;
	ans = abs(X1 - X2) + abs(Y1 - Y2);
	if(abs(a) < EPS || abs(b) < EPS){
		cout << setprecision(30) << ans << '\n';
		exit(0);
	}
	{
		long double XX1 = (-b*Y1 - c)/a;
		long double XX2 = (-b*Y2 - c)/a;
		ans = min(ans, dist(X1, Y1, XX1, Y1) + dist(XX1, Y1, XX2, Y2) + dist(XX2, Y2, X2, Y2));
	}
	{
		long double XX1 = (-b*Y1 - c)/a;
		long double YY2 = (-a*X2 - c)/b;
		ans = min(ans, dist(X1, Y1, XX1, Y1) + dist(XX1, Y1, X2, YY2) + dist(X2, YY2, X2, Y2));
	}
	{
		long double YY1 = (-a*X1 - c)/b;
		long double XX2 = (-b*Y2 - c)/a;
		ans = min(ans, dist(X1, Y1, X1, YY1) + dist(X1, YY1, XX2, Y2) + dist(XX2, Y2, X2, Y2));
	}
	{
		long double YY1 = (-a*X1 - c)/b;
		long double YY2 = (-a*X2 - c)/b;
		ans = min(ans, dist(X1, Y1, X1, YY1) + dist(X1, YY1, X2, YY2) + dist(X2, YY2, X2, Y2));
	}
	cout << setprecision(30) << ans << '\n';


	return 0;
}