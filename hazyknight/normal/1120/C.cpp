#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 5005;
const int INF = (1 << 30) - 1;

struct Node
{
	int ch[26];
	int fail,len;
}node[MAXN << 1];

int n,a,b,id = 1,last = 1;
int f[MAXN];

string s;

void extend(int c)
{
	int np = ++id,p = last;
	node[np].len = node[p].len + 1;
	while (p && !node[p].ch[c])
	{
		node[p].ch[c] = np;
		p = node[p].fail;
	}
	if (!p)
		node[np].fail = 1;
	else
	{
		int q = node[p].ch[c];
		if (node[q].len == node[p].len + 1)
			node[np].fail = q;
		else
		{
			int nq = ++id;
			node[nq].len = node[p].len + 1;
			memcpy(node[nq].ch,node[q].ch,sizeof(node[q].ch));
			node[nq].fail = node[q].fail;
			node[q].fail = node[np].fail = nq;
			while (p && node[p].ch[c] == q)
			{
				node[p].ch[c] = nq;
				p = node[p].fail;
			}
		}
	}
	last = np;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> a >> b >> s;
	for (int i = 0;i < n;i++)
		f[i] = INF;
	f[0] = a;
	for (int i = 0;i < n - 1;i++)
	{
		extend(s[i] - 'a');
		f[i + 1] = min(f[i + 1],f[i] + a);
		int cur = 1;
		for (int j = i + 1;j < n;j++)
		{
			if (!node[cur].ch[s[j] - 'a'])
				break;
			cur = node[cur].ch[s[j] - 'a'];
			f[j] = min(f[j],f[i] + b);
		}
	}
	cout << f[n - 1] << endl;
	return 0;
}