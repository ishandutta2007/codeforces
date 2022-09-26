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

const int MAXN = 805;

int n,N;
int f[12][12];
int ok[12];
int ans[MAXN];
int A[MAXN];
int pre[MAXN];

bool fix[MAXN];

bool ask(vector<int> &a)
{
	cout << "? " << a.size() << ' ';
	for (int i = 0;i < a.size();i++)
		cout << a[i] << ' ';
	cout << endl;
	cout.flush();
	int res;
	cin >> res;
	return res;
}

int getr(int p,int MOD)
{
	for (int i = 0;i < MOD;i++)
	{
		if (MOD == 8 && (pre[p] == pre[ok[0]]) != (i & 1))
			continue;
		vector<int> t;
		for (int j = 0;j < N;j++)
			if (f[MOD][(MOD - i) % MOD] >> j & 1)
				t.push_back(ok[j]);
		t.push_back(p);
		if (ask(t))
			return i;
	}
}

int main()
{
	cin >> n;
	for (int i = 2;i <= n;i++)
	{
		vector<int> t;
		t.push_back(i - 1);
		t.push_back(i);
		pre[i] = pre[i - 1] ^ ask(t) ^ 1;
	}
	for (int i = 1;i <= 5;i++)
	{
		for (int j = 1;j <= n;j++)
			if (!fix[j])
			{
				vector<int> t;
				for (int k = 1;k <= n;k++)
					if (!fix[k] && k != j)
						t.push_back(k);
				if (ask(t))
				{
					ok[N++] = j;
					if (pre[j] == pre[ok[0]])
						ans[j] = (i % 2 == 0 ? n + 1 - i : i);
					else
						ans[j] = (i % 2 == 0 ? i : n + 1 - i);
				}
			}
		fix[ok[N - 1]] = fix[ok[N - 2]] = 1;
	}
	if (n > 8)
	{
		for (int i = 1;i < (1 << N);i++)
		{
			int cnt = 0,sum = 0;
			for (int j = 0;j < N;j++)
				if (i >> j & 1)
				{
					cnt++;
					sum += ans[ok[j]];
				}
			f[cnt + 1][sum % (cnt + 1)] = i;
		}
		for (int i = 1;i <= n;i++)
			if (!fix[i])
			{
				int r3 = getr(i,3);
				int r5 = getr(i,5);
				int r7 = getr(i,7);
				int r8 = getr(i,8);
				for (int j = 5;j <= n - 4;j++)
					if (j % 3 == r3 && j % 5 == r5 && j % 7 == r7 && j % 8 == r8)
					{
						ans[i] = j;
						break;
					}
			}
	}
	if (ans[1] > n / 2)
	{
		for (int i = 1;i <= n;i++)
			ans[i] = n + 1 - ans[i];
	}
	cout << "! ";
	for (int i = 1;i <= n;i++)
		cout << ans[i] << ' ';
	cout << endl;
	cout.flush();
	return 0;
}