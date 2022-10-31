#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

int n, a[2000010], l=0;

int main() {
	cin >> n;
	for (int i=0; i<n; i++) a[i]=i+1;
	for (int k=2; k<=n; k++) {
		int last=a[l];
		for (int i=k; i<n; i+=k) {
			int tmp=a[i+l];
			a[i+l]=last;
			last=tmp;
		}
		a[n+l]=last;
		l++;
	}
	for (int i=0; i<n; i++) cout << a[i+l] << ' ';
	return 0;
}