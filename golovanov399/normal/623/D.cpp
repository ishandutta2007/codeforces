#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt();
	vector<int> p(n);
	for (int i = 0; i < n; i++){
		p[i] = 100 - nxt();
	}
	vector<double> q(n);
	for (int i = 0; i < n; i++)
		q[i] = 1;
	double ans = 0;
	clock_t start = clock();
	int cur = 0;
	while (1){
		if (clock() - start > 1.8 * CLOCKS_PER_SEC){
			break;
		}
		cur++;
		int i = 0;
		for (int j = 1; j < n; j++){
			if (q[i] > 1 - 1e-9)
				break;
			if (q[j] > 1 - 1e-9 || (1 - q[i] * p[i] / 100) / (1 - q[i]) < (1 - q[j] * p[j] / 100) / (1 - q[j]))
				i = j;
		}
		double pr = 1;
		q[i] *= 1.0 * p[i] / 100;
		for (int j = 0; j < n; j++)
			pr *= (1 - q[j]);
		ans += 1 - pr;
	}

	cout << setprecision(10) << fixed;
	cout << ans + 1 << "\n";

	return 0;
}