#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int SIZE = 2005;
const ll MOD = 1E9+7;

int arr[SIZE];

int main() {
	int n, h;
	cin >> n >> h;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] = h - arr[i];
		if(arr[i] < 0) {
			cout << 0 << '\n';
			return 0;
		}
	}
	ll resposta = 1;
	for(int i = 1; i <= n; i++) {
		if(arr[i] == arr[i-1]) {
			resposta *= arr[i-1] + 1;
		} else if(arr[i] == arr[i-1] - 1) {
			resposta *= arr[i-1];
		} else if(arr[i] != arr[i-1] + 1) {
			cout << 0 << '\n';
			return 0;
		}
		resposta = resposta % MOD;
	}
	if(arr[n] > 1) resposta = 0;
	cout << resposta << '\n';
}