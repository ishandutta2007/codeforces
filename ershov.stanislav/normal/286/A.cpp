#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

int n, a[100010];

int main() {
	cin >> n;
	if (n%4==2||n%4==3) {
		cout << -1;
		return 0;
	} else {
		for (int i=0; i<n/2; i+=2) a[i]=i+2, a[i+1]=n-i, a[n-2-i]=i+1, a[n-1-i]=n-i-1;
		if (n%2) a[n/2]=n/2+1;
		for (int i=0; i<n; i++) cout << a[i] << ' ';
	}
	return 0;
}