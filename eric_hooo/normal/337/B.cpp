#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int g1 = a / gcd(a, c) * c;
	int g2 = b / gcd(b, d) * d;
	if (g1 / a * b > g1 / c * d){
		int x = g1 / a * b - g1 / c * d;
		int y = g1 / a * b;
		int t = gcd(x, y);
		cout << x / t << "/" << y / t << endl;
	}
	else if (g2 / b * a > g2 / d * c){
		int x = g2 / b * a - g2 / d * c;
		int y = g2 / b * a;
		int t = gcd(x, y);
		cout << x / t << "/" << y / t << endl;
	}
	else cout << 0 << "/" << a / gcd(a, b) << endl;
	return 0;
}