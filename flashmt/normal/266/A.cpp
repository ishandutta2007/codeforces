#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main()
{
	int n, ans = 0;
	string s;
	
	cin >> n >> s;
	for (int i = 1; i < n; i++)
		if (s[i] == s[i - 1]) ans++;
		
	cout << ans << endl;
}