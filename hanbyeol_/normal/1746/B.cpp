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
		vector<int> V(N);
		int l1 = 0, r0 = 0;
		for(int&x: V)
		{
			cin >> x;
			if(x == 0) ++r0;
		}
		int ans = r0;
		for(int i=0; i<N; i++)
		{
			if(V[i] == 0) --r0;
			else ++l1;
			ans = min(ans, max(r0, l1));
		}
		cout << ans << '\n';
	}
}