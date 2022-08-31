#include<bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c; cin >> a >> b >> c;
	cout << min(min(a-1,b-2),c-3) * 3 + 6 << '\n';

	return 0;
}