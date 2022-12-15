#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 20;

int a[ms];
int h[4], w[4], diag[2];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	int s = 0;
	for(int i = 0; i < n * n; i++) {
		cin >> a[i];
		s += a[i];
	}
	s /= n;
	cout << s << '\n';
	srand(time(0));
	do {
	    random_shuffle(a, a+n*n);
		memset(h, 0, sizeof h);
		memset(w, 0, sizeof w);
		memset(diag, 0, sizeof diag);
		for(int i = 0; i < n * n; i++) {
			h[i / n] += a[i];
			w[i % n] += a[i];
			if(i / n == i % n) diag[0] += a[i];
			if(i / n + i % n == n - 1) diag[1] += a[i];
		}
		bool ans = diag[0] == s && diag[1] == s;
		for(int i = 0; i < n; i++) {
			ans = ans && w[i] == s && h[i] == s;
		}
		if(ans) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					cout << a[i*n + j] << ' ';
				}
				cout << '\n';
			}
			return 0;
		}
	} while(true);
	return 0;
}