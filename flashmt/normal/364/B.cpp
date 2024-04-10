#include <bits/stdc++.h>
using namespace std;

int n, D, c[55], s[55], can[500500];
vector <int> a;

int main()
{
	cin >> n >> D;
	for (int i = 1; i <= n; i++) cin >> c[i];
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + c[i];
	
	int ans = 0;
	while (ans + 1 <= n && c[ans + 1] - s[ans] <= D) ans++;
	
	if (!ans) puts("0 0");
	else
	{
		can[0] = 1;
		for (int i = 1; i <= ans; i++)
			for (int j = s[ans]; j >= c[i]; j--)
				can[j] |= can[j - c[i]];
				
		for (int i = 1; i <= s[ans]; i++)
			if (can[i]) a.push_back(i);
				
		int step = 0, cur = 0;
		while (cur < s[ans])
		{
			int next = upper_bound(a.begin(), a.end(), cur + D) - a.begin();
			cur = a[next - 1];
			step++;
		}
		
		cout << s[ans] << ' ' << step << endl;
	}
}