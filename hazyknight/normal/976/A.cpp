#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int n;
int cnt[2];
string s;

int main()
{
	cin >> n >> s;
	for (int i = 0;i < s.size();i++)
		cnt[s[i] - '0']++;
	cnt[1] = min(cnt[1],1);
	for (int i = 1;i <= cnt[1];i++)
		cout << 1;
	for (int i = 1;i <= cnt[0];i++)
		cout << 0;
	cout << endl;
	return 0;
}