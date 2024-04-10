/*input

6
tom
lucius
ginny
harry
ginny
harry

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	set<string> b;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		cout << (b.count(a) ? "YES\n" : "NO\n");
		b.insert(a);
	}


	return 0;
}