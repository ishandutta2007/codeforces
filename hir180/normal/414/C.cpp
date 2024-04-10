//IOI2014
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n,m;
vector<ll>num,num2;
ll same[25],another[25];
ll revsame[25],sum[25];
map<int,int>ma;
ll cnt(vector<ll>& a,int m)
{
	int nn=a.size();
	if(nn<=1) return 0;
	vector<ll> b(a.begin(),a.begin()+nn/2);
	vector<ll> c(a.begin()+nn/2,a.end());
	ll x = cnt(b,m);
	ll y = cnt(c,m);
	ll z = 0;
	int aa=0,bb=0,cc=0;
	while(aa<nn)
	{
		if(bb < b.size() && (cc == c.size() || b[bb] <= c[cc]))
		{
			a[aa++] = b[bb++];
		}
		else
		{
			z+=nn/2-bb;
			a[aa++] = c[cc++];
		}
	}
	if(!m) same[ma[nn]] += x+y+z; else revsame[ma[nn]] += x+y+z;
	return x+y+z;
}
int main()
{
	for(int i=0;i<=20;i++) ma[(1<<i)]=i;
	scanf("%d",&n);
	num.resize((1<<n));
	for(int i=0;i<(1<<n);i++) scanf("%lld",&num[i]);
	num2 = num; reverse(num2.begin(),num2.end());
	cnt(num,0); cnt(num2,1);
	ll all = same[n];
	for(int i=0;i<n;i++)
	{
		another[i] = all-same[i];
	}
	for(int i=0;i<=n;i++)
	{
		sum[i] = same[i]+revsame[i];
	}
	scanf("%d",&m);
	for(int j=0;j<m;j++)
	{
		int q; scanf("%d",&q);
		ll nxt=another[q] + sum[q] - same[q];
		same[q] = sum[q] - same[q];
		for(int i=q+1;i<=n;i++)
		{
			same[i] = nxt-another[i];
		}
		for(int i=q-1;i>=0;i--)
		{
			same[i] = sum[i] - same[i];
			another[i] = nxt-same[i];
		}
		printf("%lld\n",same[n]);
	}
}