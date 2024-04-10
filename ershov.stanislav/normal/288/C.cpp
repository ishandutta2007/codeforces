#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

void dfs(long long n) {
	if (n==0) {
		cout << 0;
		return;
	}
	long long x=1;
	while (x<=n) x*=2;
	x/=2;
	n-=x;
	for (int i=0; i<x; i++) {
		if (i<x-n-1) cout << x-1-i << ' ';
		else cout << x-i-1+x << ' ';
	}
	dfs(n);
}

int main() {
	long long n;
	cin >> n;
	cout << n*(n+1) << endl;
	dfs(n);
	return 0;
}