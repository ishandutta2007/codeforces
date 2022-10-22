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
		int N;
		cin >> N;
		vector<int> ans(N);
		for (int i = 1; i <= N; i++)
		{
			int x;
			cin >> x;
			ans[N - x] = i;
		}
		for (int i : ans)
			cout << i << " ";
		cout << '\n';
	}
}