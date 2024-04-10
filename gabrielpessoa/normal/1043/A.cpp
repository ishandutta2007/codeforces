#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int a[ms];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	int menor = 0;
	cin >> n;
	int soma = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		menor = max(x, menor);
		soma += x;
	}
	for(int k = menor; true; k++) {
		if(n*k > soma+soma) {
			cout << k << endl;
			return 0;
		}
	}
	cout << '\n';
}