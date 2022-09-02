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
int x[200005];
int m;
int a[300005];
int xx[300005];
ll res[300005];
int st;
bool cmp(const int &c,const int &d)
{
	return a[c] < a[d];
}
#define s (1<<17)
vector<int>seg[s*2][2];
void update(int k,int l,int r)
{
	int mid = (l+r)/2;
	int cur = 0;
	for(int i=mid;i>=l;i--)
	{
		cur = __gcd(cur,x[i]);
		seg[k][0].pb(cur);
	}
	cur = 0;
	for(int i=mid+1;i<=r;i++)
	{
		cur = __gcd(cur,x[i]);
		seg[k][1].pb(cur);
	}
	if(l == r) return ;
	update(k*2+1,l,mid);
	update(k*2+2,mid+1,r);
}
int calc(int a,int b,int k,int l,int r)
{
	int mid = (l+r)/2;
	if(b < mid) return calc(a,b,k*2+1,l,mid);
	if(a > mid+1) return calc(a,b,k*2+2,mid+1,r);
	int cur = 0;
	if(a<=mid)	
	{
		cur = __gcd(cur,seg[k][0][mid-a]);
	}
	if(b>=mid+1)
	{
		cur = __gcd(cur,seg[k][1][b-mid-1]);
	}
	return cur;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	update(0,0,s-1);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		xx[i] = i;
	}
	sort(xx,xx+m,cmp);
	sort(a,a+m);
	for(int i=0;i<n;i++)
	{
		int cur = i;
		while(cur < n)
		{
			int q = calc(i,cur,0,0,s-1);
			
			int lb = cur,ub = n;
			while(ub-lb > 1)
			{
				int mid = (lb+ub)/2;
				if(calc(i,mid,0,0,s-1) != q)
				{
					ub = mid;
				}
				else
				{
					lb = mid;
				}
			}
			int w = lower_bound(a,a+m,q)-a;
			if(a[w] == q)
			{
				res[xx[w]] += (lb-cur+1LL);
			}
			cur = lb+1;
		}
	}
	for(int i=1;i<m;i++)
	{
		if(a[i] == a[i-1])
		{
			res[xx[i]] = res[xx[i-1]];
		}
	}
	for(int i=0;i<m;i++) printf("%lld\n",res[i]);
}