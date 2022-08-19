#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define ll long long
#define maxn 105
using namespace std;
map <int, short> x;
int a[maxn];
int find(int k)
{
	if(x[k]) return x[k] - 1;
	int ans = 0;
	if(k <= 1) ans = 0;
	else
	{
		bool hv[35];
		memset(hv, 0, sizeof(hv));
		for(int j = 1; j <= 31; j++)
		{
			if(!(k >> j)) break;
			int ed = (k >> j) | (k & ((1 << j) - 1));
			int ns = find(ed);
			hv[ns] = 1;
		}
		for(int j = 0; j < 35; j++)
			if(!hv[j])
			{
				ans = j;
				break;
			}
	}
	x[k] = ans + 1;
	return ans;
}
bool bpr[35000];
int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < 35000; i++)
		bpr[i] = 1;
	for(int i = 2; i < 35000; i++)
		if(bpr[i])
		{
			x.clear();
			int nows = 0;
			for(int j = 2; i * j < 35000; j++)
				bpr[i * j] = 0;
			for(int j = 1; j <= n; j++)
			{
				int ncnt = 0;
				while(!(a[j] % i)) ncnt++, a[j] /= i;
				nows |= (1 << ncnt);
			}
			if(nows > 1)
				ans ^= find(nows);
		}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		if(a[i] != 1 && a[i] != a[i + 1])
			ans ^= 1;
	
	if(ans) printf("Mojtaba\n");
	else printf("Arpa\n");
	return 0;
}