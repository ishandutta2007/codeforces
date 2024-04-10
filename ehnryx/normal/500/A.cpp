#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define End return 0; }
#define of ios::sync_with_stdio(0);cin.tie(0);
#define story int main() {
#define The

The story of lame:
	int pizzas, weird, what;
	bitset<30001> is;
	is[1] = true;
	cin >> pizzas >> weird;
	for (int i = 1; i < pizzas; i++) {
		cin >> what;
		if (is[i] == true)
			is[i+what] = true;
	}
	cout << ((is[weird]) ? "YES" : "NO") << endl;
The End