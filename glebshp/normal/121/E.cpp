#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int block_size = 2000;
const int size = 1000 * 100;
const int maxnum = 1000 * 10 + 1;

vector <int> lck;
int mas[size], have[size / block_size + 1][maxnum], md[size / block_size + 1];
char buf[100];
int n;
bool isluck[maxnum];

void genalllucky(int num, int lim)
{
	if (num > lim)
		return;
	lck.pb(num);
	isluck[num] = true;
	genalllucky(num * 10 + 4, lim);
	genalllucky(num * 10 + 7, lim);
}

inline void change_block(int l, int r, int d, int num)
{
	if (num * block_size >= l && (num + 1) * block_size - 1 <= r)
		md[num] += d;
	else
	{
		int lb = max(l, num * block_size);
		int rb = min(r, (num + 1) * block_size - 1);
		for (int i = lb; i <= min(n - 1, rb); i++)
		{
			have[num][mas[i]]--;
			mas[i] += d;
			have[num][mas[i]]++;
		}
	}
}

void build_block(int num)
{
	int i;
	md[num] = 0;
	for (i = num * block_size; i < min(n, (num + 1) * block_size); i++)
		have[num][mas[i]]++;
}

inline int get_block_ans(int l, int r, int num)
{
	int ans = 0, i;
	if (num * block_size >= l && (num + 1) * block_size - 1 <= r)
	{
		for (i = 0; i < lck.size(); i++)
			if (lck[i] - md[num] > 0)
				ans += have[num][lck[i] - md[num]];
	}
	else
	{
		int lb = max(l, num * block_size);
		int rb = min(r, (num + 1) * block_size - 1);
		for (i = lb; i <= min(n - 1, rb); i++)
			ans += isluck[mas[i] + md[num]];
	}
	return ans;
}

int main()
{
	int m, i, bnum, j, ans, l, r, d;

    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
	/*
	freopen("input.txt", "w", stdout);
	cout << 100 * 1000 << ' ' << 100 * 1000 << endl;
	for (i = 0; i < 100 * 1000; i++)
		cout << 0 << ' ';
	cout << endl;
	for (i = 0; i < 100 * 1000; i++)
		cout << "count 2 99999" << endl;
	return 0;
	*/
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &mas[i]);
	bnum = n / block_size + (n % block_size != 0);
	for (i = 0; i < bnum; i++)
		build_block(i);
	genalllucky(4, 10000);
	genalllucky(7, 10000);
	for (i = 0; i < m; i++)
	{
		scanf("\n%s", buf);
		if (buf[0] == 'a')
		{
			scanf("%d%d%d", &l, &r, &d);
			l--, r--;
			for (j = l / block_size; j <= (r / block_size); j++)
				change_block(l, r, d, j);
		}
		else
		{
			scanf("%d%d", &l, &r);
			l--, r--;
			ans = 0;
			for (j = l / block_size; j <= (r / block_size); j++)
				ans += get_block_ans(l, r, j);
			printf("%d\n", ans);
		}
	}

    return 0;
}