#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector <int> x;
vector <int> v;


bool check(double t){
	double l = 0, r = pow(10, 9);
	for (int i = 0; i < n; ++i){
		long long int a = x[i] - v[i] * t;
		long long int b = x[i] + v[i] * t;
		if (a >= 0){
			l = max(l, x[i] - v[i] * t);
		}
		if (b <= pow(10, 9)){
			r = min(r, x[i] + v[i] * t);
		}
	}

	return r >= l;
}


int main(){
	cout.setf(ios_base::fixed);

	cin >> n;

	x.resize(n);
	v.resize(n);
	for (int i = 0; i < n; ++i){
		cin >> x[i];
	}

	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}

	double l = 0;
	double r = pow(10, 9) + 500;
	for (int i = 0; i < 100; i++){
		double m = (l + r) / 2;
		if (check(m)){
			r = m;
		}
		else{
			l = m;
		}
	}

	cout << r;
	return 0;
}