#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 1005;

int n,tota,totb;
int a[MAXN];
int b[MAXN];

ll area[MAXN];

ll ask(int t,int i,int j,int k)
{
	ll res = 0;
	cout << t << ' ' << i << ' ' << j << ' ' << k << endl;
	cout.flush();
	cin >> res;
	return res;
}

bool cmp(const int &a,const int &b)
{
	return area[a] < area[b];
}

int main()
{
	cin >> n;
	int nxt = 2;
	for (int i = 3;i <= n;i++)
		if (ask(2,1,nxt,i) < 0)
			nxt = i;
	int MAX = 0;
	for (int i = 2;i <= n;i++)
		if (i != nxt)
		{
			area[i] = ask(1,1,nxt,i);
			if (area[i] > area[MAX])
				MAX = i;
		}
	for (int i = 2;i <= n;i++)
		if (i != nxt && i != MAX)
		{
			if (ask(2,i,1,MAX) > 0)
				b[++totb] = i;
			else
				a[++tota] = i;
		}
	sort(a + 1,a + tota + 1,cmp);
	sort(b + 1,b + totb + 1,cmp);
	cout << 0 << ' ' << 1 << ' ' << nxt << ' ';
	for (int i = 1;i <= tota;i++)
		cout << a[i] << ' ';
	cout << MAX << ' ';
	for (int i = totb;i >= 1;i--)
		cout << b[i] << ' ';
	cout << endl;
	cout.flush();
	return 0;
}