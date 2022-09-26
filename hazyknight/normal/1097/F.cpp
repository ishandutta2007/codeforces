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
#include <bitset>

using namespace std;

inline char gc()
{
	static char buf[1048576],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1048576,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

const int MAXN = 100005;
const int MAXV = 7005;

int n,q,tot;
int miu[MAXV]; 
int prime[MAXV];

bitset<7001> M[MAXV];
bitset<7001> D[MAXV];
bitset<7001> S[MAXN];

bool mark[MAXV];

void init()
{
	for (int i = 1;i <= 7000;i++)
	{
		for (int j = 1;j * j <= i;j++)
			if (i % j == 0)
			{
				D[i][j] = 1;
				if (j != i / j)
					D[i][i / j] = 1;
			}
	}
	for (int i = 2;i <= 7000;i++)
	{
		if (!mark[i])
		{
			prime[++tot] = i;
			miu[i] = 1;
		}
		for (int j = 1;j <= tot && i * prime[j] <= 7000;j++)
		{
			mark[i * prime[j]] = true;
			if (i % prime[j] == 0)
			{
				miu[i * prime[j]] = 0;
				break;
			}
			miu[i * prime[j]] = miu[i];
		}
	}
	for (int i = 1;i <= 7000;i++)
		for (int j = 1;j * i <= 7000;j++)
			if (miu[j])
				M[i][i * j] = 1;
}

int main()
{
	init();
	read(n),read(q);
	for (int tp,x,y,z,i = 1;i <= q;i++)
	{
		read(tp);
		if (tp == 1)
		{
			read(x),read(y);
			S[x] = D[y];
		}
		if (tp == 2)
		{
			read(x),read(y),read(z);
			S[x] = (S[y] ^ S[z]);
		}
		if (tp == 3)
		{
			read(x),read(y),read(z);
			S[x] = (S[y] & S[z]);
		}
		if (tp == 4)
		{
			read(x),read(y);
			putchar(((S[x][y] - (S[x] & M[y]).count()) & 1) + '0');
		}
	}
	putchar('\n');
	return 0;
}