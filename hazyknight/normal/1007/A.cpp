#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 100005;

int n,head,tail,ans;
int a[MAXN];
int q[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	head = 1,tail = 0;
	for (int i = 1;i <= n;i++)
	{
		if (head <= tail && q[head] < a[i])
		{
			ans++;
			head++;
		}
		q[++tail] = a[i];
	}
	cout << ans << endl;
	return 0;
}