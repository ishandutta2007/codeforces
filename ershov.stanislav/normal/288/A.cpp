#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (k>n) {
		cout << -1;
		return 0;
	} else if (k==1&&n==1) {
		for (int i=0; i<n; i++) cout << 'a';
	} else if (k==1&&n!=1) cout << -1;
	else {
		for (int i=0; i<min(n-k+2, n); i++) cout << ((i%2)?'b':'a');
		for (char i=2; i<k; i++) cout << (char)(i+'a');
	}
	return 0;
}