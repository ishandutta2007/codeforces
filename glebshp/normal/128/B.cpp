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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int base = 17239;
const int size = 1000 * 1000;
const int rms = (1 << 18) - 1;
const int hrms = rms / 2;

int len;
char buf[size];
int st[size], h[size];
//vector <int> suf;
pair <int, int> rmq[rms + 1];


inline bool eq(int f1, int s1, int f2, int s2)
{
	return ((s1 >= 0 ? h[s1] : 0) - (f1 == 0 ? 0 : h[f1 - 1] * st[s1 - f1 + 1]) == (s2 >= 0 ? h[s2] : 0) - (f2 == 0 ? 0 : h[f2 - 1] * st[s2 - f2 + 1]));
}


bool comp(pair <int, int> p1, pair <int, int> p2)
{
	int l = 0, r = min(p1.sc - p1.fs + 1, p2.sc - p2.fs + 1), mid, st = 0;
	while (l < r)
	{
		mid = (l + r) / 2 + st;
		st ^= 1;
		if (eq(p1.fs, p1.fs + mid - 1, p2.fs, p2.fs + mid - 1))
			l = mid;
		else
			r = mid - 1;
	}
	if (l == min(p1.sc - p1.fs + 1, p2.sc - p2.fs + 1))
		return (p1.sc - p1.fs <= p2.sc - p2.fs);
	return buf[p1.fs + l] <= buf[p2.fs + l];
}


int main()
{
	int i, j, k, p;
	pair <int, int> v;
	/*
	freopen("input.txt", "w", stdout);
	for (i = 0; i < 100000; i++)
		printf("%c", 'a' + rand() % 26);
	printf("\n100000\n");
		return 0;
		*/
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

	scanf("%s", buf);
	scanf("%d", &k);
	len = strlen(buf);
	if (len * 1ll * (len + 1) / 2 < k)
	{
		printf("No such line.\n");
		return 0;
	}
	buf[len] = 'z' + 1;
	h[0] = buf[0];
	for (i = 1; i <= len; i++)
		h[i] = h[i - 1] * base + buf[i];
	st[0] = 1;
	for (i = 1; i <= len; i++)
		st[i] = st[i - 1] * base;
	/*
	for (i = 0; i < len; i++)
		suf.pb(i);
	sort(suf.begin(), suf.end(), comp);
	for (i = 0; i < len; i++)
		if (len - suf[i] >= k)
		{
			for (j = suf[i]; j < suf[i] + k; j++)
				printf("%c", buf[j]);
			printf("\n");
			return 0;
		}
		else
			k -= (len - suf[i]);
	*/
	for (i = 1; i <= rms; i++)
		rmq[i] = mp(len, len);
	for (i = 0; i < len; i++)
		rmq[i + hrms + 1] = (mp(i, i));
	for (i = hrms; i > 0; i--)
		if (comp(rmq[i * 2], rmq[i * 2 + 1]))
			rmq[i] = rmq[i * 2];
		else
			rmq[i] = rmq[i * 2 + 1];
	for (i = 0; i < k; i++)
	{
		p = 1;
		while (p <= hrms)
		{
			if (rmq[p * 2] == rmq[p])
				p *= 2;
			else
				p = p * 2 + 1;
		}
		v = rmq[p];
		rmq[p] = mp(v.fs, v.sc + 1);
		if (v.sc + 1 == len)
			rmq[p] = mp(len, len);
		while (p > 1)
		{
			p /= 2;
			if (comp(rmq[p * 2], rmq[p * 2 + 1]))
				rmq[p] = rmq[p * 2];
			else
				rmq[p] = rmq[p * 2 + 1];
		}
	}
	for (i = v.fs; i <= v.sc; i++)
		printf("%c", buf[i]);
	printf("\n");
	//assert(false);
    return 0;
}