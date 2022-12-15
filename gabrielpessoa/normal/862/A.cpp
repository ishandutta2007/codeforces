#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int a;
	int necessarios = x;
	for(int i = 0; i < n; i++) {
	    cin >> a;
	    if(a < x) {
	        necessarios--;
	    }
	    if(a == x) {
	        necessarios++;
	    }
	}
	cout << necessarios;
	return 0;
}