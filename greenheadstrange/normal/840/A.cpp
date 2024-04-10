#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define maxn 200005
#define ll long long
using namespace std;
struct th
{
	int num, pl;
	bool operator < (const th &a)const
	{
		return num < a.num;
	}
}a[maxn], b[maxn];
int m;
int ans[maxn];
int main()
{
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
		scanf("%d", &a[i].num), a[i].pl = i;
	for(int i = 0; i < m; i++)
		scanf("%d", &b[i].num), b[i].pl = i;
	sort(a, a + m), sort(b, b + m);
	for(int i = 0; i < m; i++)
		ans[b[m - 1 - i].pl] = a[i].num;
	for(int i = 0; i < m; i++)
		printf("%d ", ans[i]);
	return 0;
 }