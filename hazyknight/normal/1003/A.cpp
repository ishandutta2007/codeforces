#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <cmath> 

using namespace std;

int n,ans;
int cnt[105];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int a;
		cin >> a;
		cnt[a]++;
		ans = max(ans,cnt[a]);
	}
	cout << ans << endl;
	return 0;
}