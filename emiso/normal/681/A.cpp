#include <bits/stdc++.h>

using namespace std;

int f, a, d, n;
string str;

int main() {
	cin >> n;
	while(n--) {
		cin >> str >> a >> d;
		if(a >= 2400 && d > a) f = 1;
	}
	
	printf("%s\n", f ? "YES" : "NO");
	return 0;
}