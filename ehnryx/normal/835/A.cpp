#include <bits/stdc++.h>
using namespace std;
///////////
int main() {
	int s, va, vb, ta, tb;
	cin >> s >> va >> vb >> ta >> tb;
	if (2*ta + s*va < 2*tb + s*vb) cout << "First" << endl;
	else if (2*ta + s*va > 2*tb + s*vb) cout << "Second" << endl;
	else cout << "Friendship" << endl;
	return 0;
}