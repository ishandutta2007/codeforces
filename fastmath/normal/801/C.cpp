#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>


using namespace std;


long long sum = 0;
double eps = pow(10, -5);
int inf = pow(10, 9);
long long big_inf = pow(10, 18);
int n, p;
vector <pair <int, int> > a;


bool check(double t){
	double res = 0;
	for (int i = 0; i < n; ++i){
		res += max(0.0, a[i].first * t - a[i].second);
	}

	return res <= p * t;
}


int main(){
	ios_base::sync_with_stdio(false);

	cin >> n >> p;
	a.resize(n);

	for (int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;
		sum += a[i].first;
	}

	if (sum <= p){
		cout << -1;
	}
	else{
		double l = 0;
		double r = big_inf;
		while (r - l > eps){
			double m = (l + r) / 2;
			if (check(m)){
				l = m;
			}
			else{
				r = m;
			}
		}

		cout << r;
	}
	
	return 0;
}