#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int total = 0;
	if(--n) {
		total = min(a, b) + --n * min(min(a, b), c);
	}	
	cout << total;
}