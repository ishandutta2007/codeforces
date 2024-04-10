#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1000005;

int Q,n,m;

char s[MAXN];
char t[MAXN];

vector<pair<char,int> > S,T;

int main()
{
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%s%s",s,t);
		n = strlen(s);
		m = strlen(t);
		S.clear();
		T.clear();
		for (int i = 0;i < n;i++)
		{
			if (!S.size() || S.back().first != s[i])
				S.push_back(make_pair(s[i],1));
			else
				S.back().second++;
		}
		for (int i = 0;i < m;i++)
		{
			if (!T.size() || T.back().first != t[i])
				T.push_back(make_pair(t[i],1));
			else
				T.back().second++;
		}
		if (S.size() != T.size())
		{
			puts("NO");
			continue;
		}
		bool ok = 1;
		for (int i = 0;i < S.size();i++)
			if (S[i].first != T[i].first || S[i].second > T[i].second)
			{
				ok = 0;
				break;
			}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}