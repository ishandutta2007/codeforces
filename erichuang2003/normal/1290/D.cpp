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

const int MAXN = 1035;

int n,t,K;

namespace Real
{

bool ask(int u)
{
	cout << "? " << u << endl;
	cout.flush();
	string s;
	cin >> s;
	return s == "N";
}

void R()
{
	cout << "R" << endl;
	cout.flush();
}

}

namespace Fake
{

int cntask,cntR;
int a[MAXN];
int cnt[MAXN];

queue<int> Q;

bool ask(int u)
{
	if (++cntask > (3 * n * n) / (2 * t))
	{
		puts("ask gg");
		exit(0);
	}
	bool r = !cnt[a[u]];
	Q.push(a[u]);
	cnt[a[u]]++;
	if (Q.size() > t)
	{
		cnt[Q.front()]--;
		Q.pop();
	}
	return r;
}

void R()
{
	if (++cntR > 1000000)
	{
		puts("R gg");
		exit(0);
	}
	while (!Q.empty())
	{
		cnt[Q.front()]--;
		Q.pop();
	}
}

}

//using namespace Fake;
using namespace Real;

int ans;
bool ok[MAXN];

int main()
{
	cin >> n >> t;
	if (n == 1)
	{
		cout << "! 1" << endl;
		cout.flush();
		return 0;
	}
	K = max(t,2);
	for (int i = 1;i <= n;i++)
		ok[i] = 1;
	int C = n / (K >> 1);
	bool unR = 0;
	for (int i = 1;i < C;i++)
		for (int j = 0;j < i;j++)
		{
			if (j + i > C)
				continue;
			for (int k = 0;k * i + j < C;k++)
				for (int l = (k * i + j) * (K >> 1) + 1;l <= (k * i + j + 1) * (K >> 1);l++)
					if (!ask(l))
						ok[l] = 0;
			R();
		}
	for (int i = 1;i <= n;i++)
		ans += ok[i];
	cout << "! " << ans << endl;
	cout.flush();
	return 0;
}