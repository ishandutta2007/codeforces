#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 205;

int n;

char s[MAXN];
char t[MAXN];

vector<int> ans;

bool solve(char c)
{
	ans.clear();
	memcpy(t,s,sizeof(t));
	for (int i = 1;i < n;i++)
		if (t[i] != c)
		{
			t[i] = (t[i] == 'B' ? 'W' : 'B');
			t[i + 1] = (t[i + 1] == 'B' ? 'W' : 'B');
			ans.push_back(i);
		}
	if (t[n] != c)
		return 0;
	return 1;
}

void print()
{
	printf("%d\n",(int)ans.size());
	for (int i = 0;i < ans.size();i++)
		printf("%d ",ans[i]);
	printf("\n");
	exit(0);
}

int main()
{
	scanf("%d%s",&n,s + 1);
	if (solve('W'))
		print();
	if (solve('B'))
		print();
	puts("-1");
	return 0;
}