#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int n;

long long ans,a,b;

string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> a >> b >> s;
	s += "1";
	for (int i = 0;i + 1 < s.size();i++)
		if (s[i] == '0' && s[i + 1] == '1')
			ans++;
	if (ans == 0)
		cout << 0 << endl;
	else
		cout << min((ans - 1) * a + b,ans * b) << endl;
	return 0;
}