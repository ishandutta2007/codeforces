#include<iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	for(int i = k + 1; i > 0; i--) cout << i << ((i == 1 && n == k + 1) ? '\n' : ' ');
	for(int i = k + 2; i <= n; i++) cout << i << ((i == n) ? '\n' : ' ');
return 0;
}