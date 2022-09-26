#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cctype>

using namespace std;

int n,a,ans,MIN;
int cnt[5]; 

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a,cnt[a]++;
	if (cnt[1] <= cnt[3])
		cout << cnt[4] + cnt[3] + (cnt[2] + 1) / 2 << endl;
	else
	{
		cnt[1] -= cnt[3];
		if (cnt[2] & 1)
		{
			if (cnt[1] <= 2)
				cout << cnt[4] + cnt[3] + cnt[2] / 2 + 1 << endl;
			else
				cout << cnt[4] + cnt[3] + cnt[2] / 2 + 1 + (cnt[1] + 1) / 4 << endl;
		}
		else
			cout << cnt[4] + cnt[3] + cnt[2] / 2 + (cnt[1] + 3) / 4 << endl;
	}
	return 0;
}