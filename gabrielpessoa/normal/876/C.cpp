#include <bits/stdc++.h>
using namespace std;

long long arr[105];
int main() {
	long long n, amount = 0;
	cin >> n;
	for(long long i = max((long long) 0, n - 100); i <= n; i++) {
		long long soma = i;
		long long valor = i;
		while(valor > 0) {
			soma += valor % 10;
			valor /= 10;
		}
		if(soma == n) {
			arr[amount++] = i;
		}
	}
		cout << amount << endl;
	for(int i = 0; i < amount; i++) {
		cout << arr[i] << endl;
	}
	
}