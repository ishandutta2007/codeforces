#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath> 
#include <ctime>
#include <algorithm>
#include <set>
#include <queue>
#define maxn 10000005
#define ll long long
#define int long long
using namespace std;
int mst[maxn], phi[maxn];
bool bpr[maxn];
int cnt[maxn];  
int prs[maxn], prcnt = 0;
ll c(ll a){return a * (a - 1) / 2;}
int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a % b);
}
#undef int
int main()
{
	#define int long long
	int n;
	scanf("%I64d", &n);
	for(int i = 1; i <= n; i++)
		bpr[i] = 1, mst[i] = i, phi[i] = i;
	//prs[prcnt++] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!bpr[i]) continue;
		prs[prcnt++] = i;
		for(int j = 2; j * i <= n; j++)
			bpr[i * j] = 0;
		for(int j = 1; j * i <= n; j++)
		{
			if(i < mst[j * i]) mst[j * i] = i; 
			phi[j * i] /= i, phi[j * i] *= (i - 1);
		}
	}
	for(int i = 1; i <= n; i++)
		cnt[mst[i]]++;
	ll tot1 = 0, tot2 = 0, tot3 = 0;
	for(int i = 2; i <= n; i++)
		tot1 += (ll)(i - 1 - phi[i]);
	for(int i = 0; i < prcnt; i++)
		for(int j = i; (ll)prs[j] * (ll)prs[i] <= n && j < prcnt; j++)
		{
			if(i != j) tot2 += (ll)cnt[prs[i]] * (ll)cnt[prs[j]];
			else tot2 += c(cnt[prs[i]]);
		}
/*	ll nans = 0;
	for(int i = 2; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
		{
			if(gcd(i, j) != 1) nans++;
			else if(mst[i] * mst[j] <= n) nans += 2;
			else 
			{
				if(bpr[i] && i * 2 > n) continue;
				if(bpr[j] && j * 2 > n) continue;
				nans += 3;
			}
		}
*/	int ns = 0;
	for(int i = 0; i < prcnt; i++)
		if(prs[i] * 2 > n) ns++;
	ns++;
	tot3 = c(n - ns);
	ll ans = tot1 + 2 * (tot2 - tot1) + 3 * (tot3 - tot2);
//	cout<<tot1<<" "<<tot2<<" "<<tot3<<endl;
//	cout<<nans<<endl;
	printf("%I64d\n", ans);
	return 0; 
}