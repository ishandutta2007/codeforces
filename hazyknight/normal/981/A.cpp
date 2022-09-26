#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

string s;

bool check(int l,int r)
{
	for (int i = l,j = r;i <= r && j >= l;i++,j--)
		if (s[i] != s[j])
			return false;
	return true;
}

int ans;

int main()
{
	cin >> s;
	for (int i = 0;i < s.size();i++)
		for (int j = i;j < s.size();j++)
			if (!check(i,j))
				ans = max(ans,j - i + 1);
	cout << ans << endl;
	return 0;
}