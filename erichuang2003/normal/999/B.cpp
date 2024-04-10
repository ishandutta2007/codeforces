#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n;
int id[105];

char ans[105];

string s;

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		id[i] = i;
	for (int i = n;i >= 1;i--)
		if (n % i == 0)
			reverse(id + 1,id + i + 1);
	cin >> s;
	for (int i = 1;i <= n;i++)
		ans[id[i]] = s[i - 1];
	for (int i = 1;i <= n;i++)
		cout << ans[i];
	cout << endl;
	return 0;
}