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

int a,b,c,d,n,cnt;

vector<int> ansA[100005];
vector<int> ansB[100005];

void gg()
{
	puts("NO");
	exit(0);
}

void print(int v)
{
	if ((v & 1) && cnt > 0)
	{
		while (cnt--)
			printf("1 2 ");
	}
	if ((~v & 1) && cnt > 0)
	{
		while (cnt--)
			printf("2 1 ");
	}
	if (v != -1)
		printf("%d ",v);
}

int main()
{
	cin >> a >> b >> c >> d;
	while ((b - a > 1 && b > 2 * a) || (c - d > 1 && c > 2 * d))
	{
		b--;
		c--;
		cnt++;
	}
	n = a + b + c + d;
	if (a < 0 || b < 0 || c < 0 || d < 0)
		gg();
	if (a > b)
	{
		if (c || d || a > b + 1)
			gg();
		puts("YES");
		for (int i = 1;i <= n;i++)
			print(~i & 1);
		print(-1);
		printf("\n");
		return 0;
	}
	if (d > c)
	{
		if (a || b || d > c + 1)
			gg();
		puts("YES");
		for (int i = 1;i <= n;i++)
			print((i & 1) + 2);
		print(-1);
		printf("\n");
		return 0;
	}
	int A = b - a,B = c - d;
	for (int i = 1;i < A;i++)
	{
		ansA[i].push_back(1);
		ansA[i].push_back(0);
		ansA[i].push_back(1);
		a--;
		b -= 2;
	}
	for (int i = 1;i <= a + b;i++)
		ansA[A].push_back(i & 1);
	for (int i = 1;i < B;i++)
	{
		ansB[i].push_back(2);
		ansB[i].push_back(3);
		ansB[i].push_back(2);
		d--;
		c -= 2;
	}
	for (int i = 1;i <= c + d;i++)
		ansB[B].push_back((~i & 1) + 2);
	if (!A)
	{
		if (B <= 1)
		{
			puts("YES");
			reverse(ansA[A].begin(),ansA[A].end());
			for (int i = 0;i < ansA[A].size();i++)
				print(ansA[A][i]);
			for (int i = 0;i < ansB[B].size();i++)
				print(ansB[B][i]);
			print(-1);
			printf("\n");
			return 0;
		}
		gg();
	}
	if (!B)
	{
		if (A <= 1)
		{
			puts("YES");
			reverse(ansB[B].begin(),ansB[B].end());
			for (int i = 0;i < ansB[B].size();i++)
				print(ansB[B][i]);
			for (int i = 0;i < ansA[A].size();i++)
				print(ansA[A][i]);
			print(-1);
			printf("\n");
			return 0;
		}
		gg();
	}
	if (A > B + 1 || B > A + 1)
		gg();
	puts("YES");
	int cur = A > B,ca = 1,cb = 1;
	for (int i = 1;i <= A + B;i++,cur ^= 1)
	{
		if (cur)
		{
			for (int j = 0;j < ansA[ca].size();j++)
				print(ansA[ca][j]);
			ca++;
		}
		else
		{
			for (int j = 0;j < ansB[cb].size();j++)
				print(ansB[cb][j]);
			cb++;
		}
	}
	print(-1);
	printf("\n");
	return 0;
}