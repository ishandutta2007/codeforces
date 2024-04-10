#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <ctime>
#include <map>

using namespace std;

int n;

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		string s;
		cin >> s;
		if (s.size() <= 10)
			cout << s << endl;
		else
			cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
	}
	return 0;
}