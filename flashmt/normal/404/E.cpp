#include <bits/stdc++.h>
using namespace std;
const int OFFSET = 1000000, oo = 27081993;

string s;
vector <int> a;
int n, cnt[2000100], flag[2000100], iteration;

int canFinish(int blocked)
{
	int pos = 0;
	iteration++;
	
	flag[OFFSET] = iteration;
	cnt[OFFSET] = 1;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < abs(a[i]); j++)
		{
			if (a[i] < 0) 
			{
				if (pos - 1 > blocked) pos--;
			}
			else pos++;
			if (flag[pos + OFFSET] != iteration) 
			{
				flag[pos + OFFSET] = iteration;
				cnt[pos + OFFSET] = 0;
			}
			cnt[pos + OFFSET]++;
		}
		
	return cnt[pos + OFFSET] == 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> s;
	for (int i = 0; i < int(s.size());)
	{
		int j = i + 1;
		while (j < int(s.size()) && s[i] == s[j]) j++;
		if (s[i] == 'R') a.push_back(j - i);
		else a.push_back(i - j);
		i = j;
	}
	
	n = a.size();
	if (a[n - 1] < 0)
		for (int i = 0; i < n; i++) a[i] = -a[i];
		
	// already finished
	if (canFinish(-oo))
	{
		cout << 1 << endl;
		return 0;
	}

	// block at -1
	if (!canFinish(-1))
	{
		cout << 0 << endl;
		return 0;
	}
	
	int low = 2, high = s.size() + 2, res = 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (canFinish(-mid)) res = mid, low = mid + 1;
		else high = mid - 1;
	}
	
	cout << res << endl;
}