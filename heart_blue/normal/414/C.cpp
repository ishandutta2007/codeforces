#include <cstdlib>   
#include <cctype>   
#include <cstring>   
#include <cstdio>   
#include <cmath>   
#include <algorithm>   
#include <vector>   
#include <string>   
#include <iostream>   
#include <sstream>   
#include <map>   
#include <set>   
#include <queue>   
#include <stack>   
#include <fstream>   
#include <numeric>   
#include <iomanip>   
#include <bitset>   
#include <list>   
#include <stdexcept>   
#include <functional>   
#include <utility>   
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const int N = 21;

LL nom[N];
LL rev[N];
int a[1 << N];
int b[1 << N];
void merge(int l, int r, int n)
{
	if (l == r) return;
	int mid = (l + r) / 2;
	merge(l, mid, n - 1);
	merge(mid + 1, r, n - 1);
	int *x = &a[l];
	int *y = &a[mid + 1];
	int c1, c2;
	c1 = c2 = 0;
	int k = 0;
	int total = 1 << (n - 1);
	while (c1 < total || c2 < total)
	{
		if (c1 == total)
		{
			while (c2 < total) b[k++] = y[c2++];
			break;
		}
		if (c2 == total)
		{
			while (c1 < total) b[k++] = x[c1++];
			break;
		}
		if (x[c1] <= y[c2])
		{
			b[k++] = x[c1++];
		}
		else
		{
			b[k++] = y[c2++];
			rev[n] += total - c1;
		}
	}
	
	c1 = c2 = 0;
	while (c1 < total && c2 < total)
	{
		if (x[c1] < y[c2])
		{
			nom[n] += total - c2;
			c1++;
		}
		else
		{
			c2++;
		}
	}
	memcpy(a + l, b, sizeof(a[0])*(1<<n));

}
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= (1 << n); i++) scanf("%d", &a[i]);
	MEM(nom, 0);
	MEM(rev, 0);
	merge(1, (1 << n), n);
	scanf("%d", &m);
	while (m--)
	{
		int q;
		int k = 1;
		scanf("%d", &q);
		while (q--)
		{
			swap(rev[k], nom[k]);
			k++;
		}
		k = n;
		LL sum = 0;
		while (k) sum += rev[k--];
		printf("%I64d\n", sum);
	}

	return 0;
}