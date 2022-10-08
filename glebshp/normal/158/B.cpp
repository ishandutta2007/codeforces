#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

int main() {
	int n, cnt[5], d;

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= 4; i++)
		cnt[i] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> d;
		cnt[d]++;
	}
	ans = cnt[4];
	cnt[4] = 0;
	while (cnt[3] > 0)
	{
		ans++;
		cnt[3]--;
		cnt[1] = max(0, cnt[1] - 1);
	}
	while (cnt[2] > 0)
	{
		if (cnt[2] > 1)
		{
			cnt[2] -= 2;
			ans++;
		}
		if (cnt[2] == 1)
		{
			ans++;
			cnt[1] = max(0, cnt[1] - 2);
			cnt[2] = 0;
		}
	}
	while (cnt[1] > 0)
	{
		ans++;
		cnt[1] -= 4;
	}
	cout << ans << endl;

	return 0;
}