#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const long double EPS = 1e-9;
int n, p, a[N], b[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> p;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		if(sum > p){
			break;
		}
	}
	if(sum <= p){
		cout << -1 << '\n';
		exit(0);
	}
	long double lo = 0.0, hi = 1e11;
	for(int iter = 0; iter < 120; iter++){
		long double t = (lo + hi)/2;
		long double lambda = 0.0;
		for(int i = 0; i < n; i++){
			lambda += max(0.0L, (t*a[i] - b[i])/p);
		}
		if(lambda < t + EPS)lo = t;
		else hi = t;
	}
	cout << fixed << setprecision(20) << lo << '\n';

	return 0;
}