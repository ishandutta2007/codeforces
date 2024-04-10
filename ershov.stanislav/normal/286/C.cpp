#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

int n, t, p[1000010], st[1000010], l=0;

int main() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> p[i];
	cin >> t;
	for (int i=0; i<t; i++) {
		int a=0;
		cin >> a;
		p[a-1]=-p[a-1];
	}
	for (int i=n-1; i>=0; i--) {
		if (p[i]<0) st[l]=-p[i], l++;
		else {
			if (l==0||st[l-1]!=p[i]) st[l]=p[i], l++, p[i]=-p[i];
			else l--;
		}
	}
	if (l) {
		cout << "NO";
	} else {
		cout << "YES" << endl;
		for (int i=0; i<n; i++) cout << p[i] << ' ';
	}
	return 0;
}