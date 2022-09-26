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

const int MAXN = 300005;

int n;

char s[MAXN];

vector<pair<char,int> > v;

int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for (int i = 1;i <= n;i++)
	{
		if (!v.size() || v.back().first != s[i])
			v.push_back(make_pair(s[i],1));
		else
			v.back().second++;
	}
	if (~v.size() & 1)
		puts("0");
	else
	{
		for (int i = 0,j = v.size() - 1;i < j;i++,j--)
			if (v[i].first != v[j].first || v[i].second + v[j].second < 3)
			{
				puts("0");
				return 0;
			}
		if (v[v.size() / 2].second < 2)
			puts("0");
		else
			printf("%d\n",v[v.size() / 2].second + 1);
	}
	return 0;
}