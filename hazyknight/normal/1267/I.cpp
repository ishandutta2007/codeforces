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

int T,n,tot;
int size[MAXN];

vector<int> e[MAXN];
priority_queue<pair<int,int> > Q;

bool ask(int a,int b)
{
	cout << "? " << a << ' ' << b << endl;
	cout.flush();
	char c;
	cin >> c;
	return c == '<';
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		while (!Q.empty())
			Q.pop();
		for (int i = 1;i <= 2 * n;i++)
		{
			Q.push(make_pair(1,i));
			size[i] = 1;
			e[i].clear();
		}
		tot = 0;
		while (tot < n)
		{
			pair<int,int> u = Q.top();
			Q.pop();
			pair<int,int> v = Q.top();
			Q.pop();
			if (u.first + v.first == n)
			{
				pair<int,int> w = Q.top();
				Q.pop();
				if (w.first + u.first == n)
				{
					Q.push(u);
					u = w;
				}
				else
				{
					Q.push(v);
					v = w;
				}
			}
			if (u.first + v.first != n)
			{
				bool r = ask(u.second,v.second);
				if (u.first + v.first > n)
				{
					tot++;
					if (!r)
						swap(u,v);
					for (int i = 0;i < e[u.second].size();i++)
						Q.push(make_pair(size[e[u.second][i]],e[u.second][i]));
					Q.push(v);
				}
				else
				{
					if (!r)
						swap(u,v);
					u.first = (size[u.second] += size[v.second]);
					e[u.second].push_back(v.second);
					Q.push(u);
				}
			}
		}
		cout << "!" << endl;
		cout.flush();
	}
	return 0;
}