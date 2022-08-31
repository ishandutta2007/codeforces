#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int n;
int x[maxn], y[maxn];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 2; i <= n; i++) {
			while (d >= i - 1 && x[i]) {
				d -= (i - 1), x[i]--, x[1]++;
			}
		}
		cout << x[1] << endl;
	} 
	return 0;
}