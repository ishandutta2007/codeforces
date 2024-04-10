#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int res = 0;
	for(int i = 1; true; i++) {
		if(n == 0) {
			cout << i - 1 << '\n';
			return 0;
		}
		n--;
		if(i % m == 0) n++;
	}
	return 0;
}