#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n;
int a[100005];
int cnt[100005];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	int nott = 0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]%2 == 1) nott++;
	}
	if(nott >= 2)
	{
		puts("0"); return 0;
	}
	
	int i=0,j=n-1;
	while(i<=j)
	{
		if(a[i] != a[j]) break;
		i++; j--;
	}
	if(i > j)
	{
		printf("%lld\n",1LL*n*(n+1)/2);
		return 0;
	}
	ll res = 0;
	//contain [i,j]
	res += 1LL*(i+1)*(n-j);
	int cur = j-1;
	int c[100005]={};
	for(int x=j+1;x<n;x++) c[a[x]]++;
	while(i <= cur)
	{
		//check [i,cur]
		if(cur >= n/2 || (n%2 == 0 && cur == n/2-1))
		{
			c[a[cur+1]]++;
			if(c[a[cur+1]]*2 > cnt[a[cur+1]]) goto en;
		}
		else if(n%2 == 1 && cur == n/2-1)
		{
			c[a[cur+1]]++;
			if(c[a[cur+1]]*2-1 != cnt[a[cur+1]]) goto en;
		}
		else
		{
			if(a[cur+1] != a[n-2-cur]) goto en;
		}
		cur--;
	}
	en:;
	res += 1LL*(i+1)*(j-1-cur);

	cur = i+1;
	int d[100005]={};
	for(int x=0;x<i;x++) d[a[x]]++;
	while(cur <= j)
	{
		//check [cur,j]
		if(cur <= n/2)
		{
			d[a[cur-1]]++;
			if(d[a[cur-1]]*2 > cnt[a[cur-1]]) goto en1;
		}
		else if(n%2 == 1 && cur == n/2+1)
		{
			d[a[cur-1]]++;
			if(d[a[cur-1]]*2-1 != cnt[a[cur-1]]) goto en1;
		}
		else
		{
			if(a[cur-1] != a[n-cur]) goto en1;
		}
		cur++;
	}
	en1:;
	res += 1LL*(i+1)*(cur-i-1);
	
	cout << res << endl;
}