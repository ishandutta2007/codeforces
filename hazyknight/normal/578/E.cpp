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

const int MAXN = 100005;

int n,ans;
int to[MAXN];

bool vis[MAXN];

char s[MAXN];

set<int> L,R;

vector<int> LR,RL,ANS;
vector<vector<int> > LL,RR;

void append(vector<int> &a,vector<int> &b)
{
	for (int i = 0;i < b.size();i++)
		a.push_back(b[i]);
}

int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for (int i = 1;i <= n;i++)
	{
		if (s[i] == 'L')
			L.insert(i);
		else
			R.insert(i);
	}
	ans = n - 1;
	for (int i = 1;i <= n;i++)
	{
		if (s[i] == 'L')
		{
			set<int>::iterator it = R.lower_bound(i);
			if (it == R.end())
				continue;
			to[i] = *it;
			R.erase(it);
			ans--;
		}
		else
		{
			set<int>::iterator it = L.lower_bound(i);
			if (it == L.end())
				continue;
			to[i] = *it;
			L.erase(it);
			ans--;
		}
	}
	printf("%d\n",ans);
	for (int i = 1;i <= n;i++)
	{
		if (vis[i])
			continue;
		int cur = i;
		vector<int> path;
		while (cur)
		{
			path.push_back(cur);
			vis[cur] = 1;
			cur = to[cur];
		}
		if (s[path[0]] == 'L')
		{
			if (s[path.back()] == 'L')
				LL.push_back(path);
			else
				append(LR,path);
		}
		else
		{
			if (s[path.back()] == 'R')
				RR.push_back(path);
			else
				append(RL,path);
		}
		while (LL.size() && RR.size())
		{
			append(LR,LL.back());
			append(LR,RR.back());
			LL.pop_back();
			RR.pop_back();
		}
	}
	int op = -1;
	if (LR.size() && RL.size())
	{
		if (LR.back() > RL.back())
		{
			op = 0;
			int bk = LR.back();
			LR.pop_back();
			append(LR,RL);
			LR.push_back(bk);
		}
		else
		{
			op = 1;
			int bk = RL.back();
			RL.pop_back();
			append(RL,LR);
			RL.push_back(bk);
		}
	}
	else if (LR.size())
		op = 0;
	else if (RL.size())
		op = 1;
	if (LL.size())
	{
		if (op == -1)
			append(ANS,LL[0]);
		if (op == 0)
		{
			append(ANS,LR);
			append(ANS,LL[0]);
		}
		if (op == 1)
		{
			append(ANS,LL[0]);
			append(ANS,RL);
		}
	}
	else if (RR.size())
	{
		if (op == -1)
			append(ANS,RR[0]);
		if (op == 0)
		{
			append(ANS,RR[0]);
			append(ANS,LR);
		}
		if (op == 1)
		{
			append(ANS,RL);
			append(ANS,RR[0]);
		}
	}
	else
	{
		if (op == 0)
			append(ANS,LR);
		else
			append(ANS,RL);
	}
	for (int i = 0;i < ANS.size();i++)
		printf("%d ",ANS[i]);
	printf("\n");
	return 0;
}