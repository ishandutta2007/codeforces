#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef unsigned long long ull;

const int MAXN = 50005;
const ull MUL = 29;

int len;
ull h[MAXN];
ull power[MAXN];

char s[MAXN];

void init()
{
	h[0] = 0;
	for (int i = 0;i < len;i++)
		h[i + 1] = h[i] * MUL + s[i] - 'a';
}

ull gethash(const int &pos,const int &length)
{
	return h[pos + length] - h[pos] * power[length];
}

int LCP(const int &i,const int &j)
{
	int low = 0,high = len - max(i,j);
	while (low < high)
	{
		int mid = (low + high + 1) >> 1;
		if (gethash(i,mid) != gethash(j,mid))
			high = mid - 1;
		else
			low = mid;
	}
	return low;
}

int LCS(const int &i,const int &j)
{
	int low = 0,high = min(i,j);
	while (low < high)
	{
		int mid = (low + high + 1) >> 1;
		if (gethash(i - mid + 1,mid) != gethash(j - mid + 1,mid))
			high = mid - 1;
		else
			low = mid;
	}
	return low;
}

bool check(const int &l)
{
	for (int i = 0;i + l < len;i += l)
		if (LCP(i,i + l) + LCS(i,i + l) >= l)
			return true;
	return false;
}

void solve(int l)
{
	int j = l;
	for (int i = l,k = 0;i < len;i++)
	{
		if (s[i] == s[i - l])
			k++;
		else
			k = 0;
		if (k == l)
		{
			j -= l;
			k = 0;
		}
		s[j++] = s[i];
	}
	len = j;
}

int main()
{
	ios::sync_with_stdio(false);
	power[0] = 1;
	for (int i = 1;i < MAXN;i++)
		power[i] = power[i - 1] * MUL;
	cin >> s;
	len = strlen(s);
	init();
	for (int i = 1;(i << 1) <= len;i++)
		if (check(i))
		{
			solve(i);
			init();
		}
	for (int j = 0;j < len;j++)
		cout << s[j];
	cout << endl;
	return 0;
}