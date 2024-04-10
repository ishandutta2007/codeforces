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
int seg[(1<<18)][61];
int x[100005],n;
int cur;
void update(int pos,int x)
{
	pos += (1<<17)-1;
	for(int j=0;j<60;j++)
	{
		if(j%x == 0)
		{
			seg[pos][j] = 2;
		}
		else
		{
			seg[pos][j] = 1;
		}
	}
	while(pos > 0)
	{
		pos = (pos-1)/2;
		for(int j=0;j<60;j++)
		{
			int a = (j+seg[pos*2+1][j])%60;
			seg[pos][j] = seg[pos*2+1][j] + seg[pos*2+2][a];
		}
	}
}
int query(int a,int b,int k,int l,int r)
{
	if(r<a || b<l) return 0;
	if(a<=l && r<=b)
	{
		int ret = seg[k][cur];
		cur = (cur+ret)%60;
		return ret;
	}
	int lk = query(a,b,k*2+1,l,(l+r)/2);
	int rk = query(a,b,k*2+2,(l+r)/2+1,r);
	return lk+rk;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		update(i,x[i]);
	}
	int q; scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		string s;
		cin >> s;
		if(s == "A")
		{
			int x,y; scanf("%d%d",&x,&y); cur = 0;
			printf("%d\n",query(x,y-1,0,0,(1<<17)-1));
		}
		else
		{
			int pos,x; scanf("%d%d",&pos,&x);
			update(pos,x);
		}
	}
}