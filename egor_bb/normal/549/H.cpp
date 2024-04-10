#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
//const int SZ = 470;
const double eps = 1e-15;

using namespace std;


double a, b, c, d;

double min (double a, double b, double c , double d){
	return (min( min(a, b), min(c, d)));
}

double max (double a, double b, double c , double d){
	return (max( max(a, b), max(c, d)));
}

int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	cout.precision(12);
	cin >> a >> b >> c >> d;
		double l = 0, r = 5 * 1e9;
		for (int i = 0; i < 1e7; i++){
			double m = (l + r) / 2.;
			double m1, m2, m3, m4, m5, m6, m7, m8;
			m1 = (a - m) * (d - m);
			m2 = (a - m) * (d + m);
			m3 = (a + m) * (d - m);
			m4 = (a + m) * (d + m);
			m5 = (b + m) * (c + m);
			m6 = (b - m) * (c + m);
			m7 = (b + m) * (c - m);
			m8 = (b - m) * (c - m);
			if (min(m1, m2, m3, m4) > max(m5, m6, m7,m8) || max(m1, m2, m3, m4) < min(m5, m6, m7,m8)) l = m; 
			else r = m;
		}
		cout << fixed << l << '\n';
}