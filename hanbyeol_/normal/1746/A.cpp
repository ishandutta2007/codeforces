#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
		vector<int> V(N);
		for (int &x : V)
			cin >> x;
		if (*max_element(V.begin(), V.end()) == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}