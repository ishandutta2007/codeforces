#pragma comment (linker, "/STACK:100000000000")
 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e17 + 7)
#define sort stable_sort
 
using namespace std;
 
 
double x[2], y[2], n, ans = 0;
double a, b, c;

double vec(double x, double y, double xx, double yy){
	return xx * y - yy * x;
}
 
int main(){
//	ifstream cin ("input.txt");
	for (int i = 0; i < 2; i++) cin >> x[i] >> y[i];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b >> c;
		double g[2];
		if (b != 0 && a != 0){
			g[0] = -(c - 103.5 * a) * 1. / b;
			g[1] = -(c - 102.5 * a) * 1. / b - g[0];
			if (vec(x[0] + 103.5, y[0] - g[0], 1, g[1]) * vec(x[1] + 103.5, y[1] - g[0], 1, g[1]) < 0) ans++;
		} else if (b == 0){
			double xx = -c * 1. / a;
			if ((xx - x[0]) * (xx - x[1]) < 0) ans++;
		} else {
			double yy = -c * 1. / b;
			if ((yy - y[0]) * (yy - y[1]) < 0) ans++;
		}
	}
	cout << ans << '\n';

    return 0;
}