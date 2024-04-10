#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	string s, t;
	cin >> s >> t;
	int i = 0;
	for (char move: t) {
		char cur = s[i];
		if (move == cur) ++i;
	}
	cout << i + 1 << endl;
	return 0;
}