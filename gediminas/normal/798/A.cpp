/*input
abbcca

*/
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	string a;
	cin >> a;
	int net = 0;

	for (int i = 0; i < a.size() / 2; i++) {
		if (a[i] != a[a.size() - i - 1])
			net++;
	}

	if (net == 1 or (net == 0 and a.size() % 2 == 1))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}