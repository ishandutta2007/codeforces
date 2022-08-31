#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define maxn 1005
#define ll long long
using namespace std;
ll n, m, s;
bool bpr[maxn];
int prms[500], prcnt = 0;
ll ns[50], nnum[50], ncnt = 0;
void ext(int a)
{
	int ns = a;
	for(int i = 0; i < prcnt; i++)
		while(!(a % prms[i])) a /= prms[i];
	if(a != 1) prms[prcnt++] = a;
}
ll ans = 0;
void count(int tm, ll num)
{
	// num  dfstm
	if(!num) return ;
	 if(tm == ncnt)
	 {
	 	ans++;
	 	return ;
	 }
	 ll tw = 1;
	 for(int i = 0; i <= nnum[tm]; i++)
	 {
	 	count(tm + 1, num / tw);
	 	tw *= ns[tm];
	 }
}
void dfs(ll tm, ll num, int t)
{
	if(!num) return;
	if(tm == ncnt)
	{
		ans += num * t;
		return ;
	}
	dfs(tm + 1, num / ns[tm], -t);
	dfs(tm + 1, num, t);
}
ll gcd(ll a, ll b)
{
	if(!b) return a;
	return gcd(b, a % b);
}
int main()
{
	for(int i = 0; i < maxn; i++)
		bpr[i] = 1;
	for(int i = 2; i < maxn; i++)
	{
		if(!bpr[i]) continue;
		prms[prcnt++] = i;
		for(int j = 2; j * i < maxn; j++)
			 bpr[j * i] = 0;
	}
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{	
		ll n1, n2, n3;
		ll m1, m2, m3;
		ll s1, s2, s3;
		scanf("%I64d%I64d%I64d", &n1, &n2, &n3);
		scanf("%I64d%I64d%I64d", &m1, &m2, &m3);
		scanf("%I64d%I64d%I64d", &s1, &s2, &s3);
		n = n1 * n2 * n3, m = m1 * m2 * m3, s = s1 * s2 * s3;
		s *= 2;
		int lcnt = prcnt;
		ext(n1), ext(n2), ext(n3), 
		ext(m1), ext(m2), ext(m3), 
		ext(s1), ext(s2), ext(s3);
		ll gc = s;
		ncnt = 0;
		memset(nnum, 0, sizeof(nnum));
		ans = 0;
		for(int i = 0; i < prcnt; i++)
			if(!(gc % prms[i]))
			{
				ns[ncnt] = prms[i];
				while(!(gc % prms[i]))
					nnum[ncnt]++, gc /= prms[i];
				ncnt++;
			}
		count(0, n);
	//	ll brans = 0;
	//	for(int i = 1; i <= n; i++)
	//		if(!(s % i)) brans++;
	//	cout<<brans<<endl; 
		// count n
		// <= m  n (n, s) 
		gc = gcd(n, s);
		ll ln = n;
		
		ncnt = 0;
		memset(nnum, 0, sizeof(nnum));
		gc = n / gcd(n, s);
	//	for(int i = 1; i <= m; i++)
	//		if(!(s % (gcd(i, n)))) brans++;
	//	cout<<brans<<endl;
		for(int i = 0; i < prcnt; i++)
			if(!(gc % prms[i]))
			{
				ns[ncnt] = 1;
				while(!(s % prms[i])) 
					ns[ncnt] *= prms[i], s /= prms[i];
				ns[ncnt] *= prms[i];
 				ncnt++;
			}
		dfs(0, m, 1);
		printf("%I64d\n", ans);
		prcnt = lcnt;
	}
	return 0;
} 
/*
1
2 8 10
4 2 2
8 3 7
*/