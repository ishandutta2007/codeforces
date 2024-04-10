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
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
ll bit[(1<<14)+5];
int f(int x)
{
	return x&-x;
}
void add(int i,ll x)
{
	if(i==0) return ;
	for(int s=i;s<=(1<<14);s+=f(s)) bit[s]+=x;
}
ll sum(int i)
{
	ll res=0;
	for(int s=i;s>0;s-=f(s)) res+=bit[s];
	return res;
}
ll bit2[(1<<14)+5];

void add2(int i,ll x)
{
	if(i==0) return ;
	for(int s=i;s<=(1<<14);s+=f(s)) bit2[s]+=x;
}
ll sum2(int i)
{
	ll res=0;
	for(int s=i;s>0;s-=f(s)) res+=bit2[s];
	return res;
}
int n;
ll a[100005];
ll b[100005];
vector<ll>got[100005];
ll val[100005];
int cnt[100005];
vector<ll>remed[100005];
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i] >> b[i];
		if(b[i] == 0) a[i] = 0;
		got[a[i]].pb(b[i]);
		add(b[i],1);
		add2(b[i],b[i]);
	}
	for(int i=1;i<=100000;i++) sort(got[i].begin(),got[i].end());
	for(int i=1;i<=100000;i++)
	{
		for(int j=got[i].size();j>=1;j--)
		{
			val[j] += got[i][got[i].size()-j];
			cnt[j] ++;
			remed[j].pb(got[i][got[i].size()-j]);
		}
	}
	ll res = 1e18;
	int rui = got[0].size();
	ll rui2 = 0;
	for(int i=n;i>=0;i--)
	{
		ll ret = 0;
		rui2 += val[i];
		rui += cnt[i];
		if(rui > i) continue;
		for(int j=0;j<remed[i].size();j++) add(remed[i][j],-1);
		for(int j=0;j<remed[i].size();j++) add2(remed[i][j],-remed[i][j]);
		int rem = i-rui;
		int lb = 0,ub = 10000;
		while(ub-lb > 1)
		{
			int mid = (lb+ub)/2;
			if(sum(mid) >= rem) ub = mid;
			else lb = mid;
		}
		ret += sum2(ub);
		ret -= 1LL*ub*(sum(ub)-rem);
		ret += rui2;
		res = min(res,ret);
	}
	cout << res << endl;
}