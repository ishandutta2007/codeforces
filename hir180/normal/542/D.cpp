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
int nxt[7005][7005];
ll dp[7005];
int cnt[7005];
bool u[1000010];
map<ll,bool>ma;
ll C[55][55];
bool isprime(ll v)
{
	if(ma.find(v) != ma.end()) return ma[v];
	for(ll i=2;i*i<=v;i++)
	{
		if(v%i==0) return ma[v] = 0;
	}
	return ma[v] = 1;
}
ll ex(ll q,int v)
{
	ll lb = 1,ub = 2000005LL;
	while(ub-lb > 1)
	{
		ll mid = (lb+ub)/2;
		ll cur = 1;
		for(int i=0;i<v;i++)
		{
			if(1000000000000000LL/cur < mid) goto FAIL;
			cur *= mid; if(cur>q) goto FAIL;
		}
		lb=mid; continue; FAIL:; ub=mid;
	}
	if(lb==1) return -2;
	ll cur = 1;
	for(int i=0;i<v;i++) cur *= lb;
	if(cur != q) return -1;
	else return lb;
}
int main()
{
	ll a; cin >> a;
	vector<ll>div;
	for(ll i=1;i*i<=a;i++)
	{
		if(a%i == 0) div.pb(i);
		if(a%i == 0 && i*i != a) div.pb(a/i);
	}
	sort(div.begin(),div.end());
	memset(nxt,-1,sizeof(nxt));
	for(int i=0;i<div.size();i++)
	{
		int y = i;
		for(int j=i;j<div.size();j++)
		{
			if(1000000000000000LL/div[i] < div[j]) break;
			ll x = div[i]*div[j];
			while(div[y]<x && y<div.size()) y++;
			if(y == div.size()) break;
			if(div[y] == x)
			{
				nxt[i][j] = y; nxt[j][i] = y;
			}
		}
	}
	for(int i=2;i<=1000005;i++)
	{
		if(u[i]) continue;
		for(int j=2;i*j<=1000005;j++)
		{
			u[i*j] = true;
		}
	}
	map<ll,vector<int> >ma;
	for(int i=0;i<div.size();i++)
	{
		ll val = div[i]-1;
		if(val <= 1) continue;
		for(int j=1;j<50;j++)
		{
			ll w = val;
			if(j>1) w = ex(val,j);
			if(w==-2) break;
			if(w > 0)
			{
				if(w <= 1000005)
				{
					if(!u[w])
					{
						ma[w].pb(i);
					}
				}
				else
				{
					if(isprime(w)) {ma[w].pb(i);}
				}
			}
		}
	}
	dp[0] = 1LL;
	C[0][0]=1LL;
	for(int i=1;i<=50;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!j){ C[i][j]=1LL;}
			else if(j==i){ C[i][j]=1LL;}
			else{C[i][j]=(C[i-1][j]+C[i-1][j-1]);}
		}
	}
	for(map<ll,vector<int> >::iterator it=ma.begin();it!=ma.end();++it)
	{
		vector<int>v = it->sc;	
		for(int j=div.size()-1;j>=0;j--)
		{
			for(int k=0;k<v.size();k++)
			{
				if(nxt[j][v[k]] == -1) continue;
				dp[nxt[j][v[k]]] += dp[j];
			}
		}
	}
	cout << dp[div.size()-1] << endl;
}