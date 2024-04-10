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
#include <stack>
#include <sstream>
using namespace std;

int next[1555 * 1555][26], node = 1, k;
string s, isGood;

void addTrie(int x, int cur, int end)
{
	if (cur < end) return;
	int ch = s[cur] - 'a';
	if (!next[x][ch]) next[x][ch] = ++node;
	addTrie(next[x][ch], cur - 1, end);
}

int main()
{
	cin >> s >> isGood >> k;
	
	int n = s.size(), cntBad = 0;
	for (int i = 0, j = -1; i < n; i++)
	{
		int x = s[i] - 'a';
		if (isGood[x] == '0') cntBad++;
		while (cntBad > k) cntBad -= isGood[s[++j] - 'a'] == '0';
		addTrie(1, i, j + 1);
	}
	
	cout << node - 1 << endl;
}