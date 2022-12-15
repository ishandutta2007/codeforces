#include <bits/stdc++.h>
using namespace std;

string a, b;

string mergesort(string &a) {
	if(a.size() % 2 == 1) {
		return a;
	} else {
		int n = a.size()/2;
		string c = a.substr(0, n), d = a.substr(n, n);
		c = mergesort(c); d = mergesort(d);
		if(c <= d) return c + d;
		else return d + c;
	}
}

int main() {
	cin >> a >> b;	
	a = mergesort(a); b = mergesort(b);
	(a == b) ? cout <<  "YES" : cout << "NO";
	cout << endl;
	return 0;
}