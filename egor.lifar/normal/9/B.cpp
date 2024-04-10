#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set> 


using namespace std;


#define INF 1000000000.00
#define eps 0.000001


double dlina(double x, double y, double x1, double y11) {
	return sqrt((x - x1) * (x - x1) + (y - y11) * (y - y11));
}


int n;
double vb, vs, x[1000], x1, y11;


int main(){
	cin >> n >> vb >> vs;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	cin >> x1 >> y11;
	double s1 = INF;
	double ans = INF;
	int k;
	for (int i = 1; i < n; i++) {
		if (x[i] / vb + dlina(x[i], 0.00, x1, y11) / vs < ans || (abs(x[i] / vb + dlina(x[i], 0.00, x1, y11) / vs - ans) < eps && dlina(x[i], 0, x1, y11) < s1)) {
		   ans = x[i] / vb + dlina(x[i], 0.00, x1, y11) / vs;
		   s1 = dlina(x[i], 0, x1, y11);
		   k = i + 1;
		}
	}
	cout << k << endl;
	return 0;
}