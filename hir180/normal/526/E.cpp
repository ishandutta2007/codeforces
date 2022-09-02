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
int v[1000005];
ll rui[2000005];
int nxt[1000005];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	rui[0] = (ll)v[0];
	for(int i=1;i<2*n;i++) rui[i] = rui[i-1]+v[i%n];
	for(int i=0;i<q;i++)
	{
		ll v; scanf("%lld",&v);
		if(v >= rui[n-1])
		{
			printf("%d\n",1); continue;
		}
		int nx = 0;
		int x = INF; ll y = 1e18;
		int pos ;
		for(int j=0;j<n;j++)
		{
			while(rui[nx]-(j==0?0:rui[j-1]) <= v) nx++;
			//[j,nx)
			nxt[j] = nx-1;
			if(nx-j < x || (nx-j==x&&y<rui[nx-1]-(j==0?0:rui[j-1])))
			{
				x = nx-j;
				y = rui[nx-1]-(j==0?0:rui[j-1]);
				pos = j;
			}
		}
		int res = INF;
		for(int j=pos;j<=pos+x;j++)
		{
			int k = j%n;
			int cur = k;
			int cnt = 0;
			//cur~cur+n-1
			while(cur < k+n)
			{
				if(cur<n) cur = nxt[cur]+1; else cur = nxt[cur%n]+n+1;
				cnt++;
			}
			res = min(res,cnt);
		}
		printf("%d\n",res);
	}
}