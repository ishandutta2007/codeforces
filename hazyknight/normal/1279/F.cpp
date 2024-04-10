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

typedef long long ll;

const int MAXN = 1000005;

int n,k,l;
int a[MAXN];
int sum[MAXN];

char s[MAXN];

pair<ll,int> f[MAXN];

pair<ll,int> operator + (const pair<ll,int> &a,const pair<ll,int> &b)
{
	return make_pair(a.first + b.first,a.second + b.second);
}

void getans(int v)
{
	memset(f,0,sizeof(f));
	for (int i = l;i <= n;i++)
		f[i] = max(f[i - 1],f[i - l] + make_pair(sum[i] - sum[i - l] + v,1));
}

int solve()
{
	for (int i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	int low = -n,high = n;
	while (low < high)
	{
		int mid = low + high >> 1;
		getans(mid);
		if (f[n].second >= k)
			high = mid;
		else
			low = mid + 1;
	}
	getans(low);
	return sum[n] - f[n].first + (ll)low * k;
}

int main()
{
	scanf("%d%d%d%s",&n,&k,&l,s + 1);
	if ((ll)k * l >= n)
	{
		puts("0");
		return 0;
	}
	for (int i = 1;i <= n;i++)
		a[i] = s[i] >= 'A' && s[i] <= 'Z';
	int ansup = solve();
	for (int i = 1;i <= n;i++)
		a[i] = s[i] >= 'a' && s[i] <= 'z';
	int anslw = solve();
	printf("%d\n",min(ansup,anslw));
	return 0;
}