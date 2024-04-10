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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000009
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n;
int x[100005],y[100005];
ll mul[100005];
vector<int>res;
set<P>se;
map<P,int>ma;
bool check(int xx,int yy)
{
	if(yy == -1) return true;
		if(se.find(mp(xx-1,yy+1)) != se.end())
		{
			bool xa = false;
			xa |= (se.find(mp(xx-2,yy)) != se.end());
			xa |= (se.find(mp(xx-1,yy)) != se.end());
			if(!xa)
			{
				return false;
			}
		}
		if(se.find(mp(xx,yy+1)) != se.end())
		{
			bool xa = false;
			xa |= (se.find(mp(xx+1,yy)) != se.end());
			xa |= (se.find(mp(xx-1,yy)) != se.end());
			if(!xa)
			{
				return false;
			}
		}
		if(se.find(mp(xx+1,yy+1)) != se.end())
		{
			bool xa = false;
			xa |= (se.find(mp(xx+1,yy)) != se.end());
			xa |= (se.find(mp(xx+2,yy)) != se.end());
			if(!xa)
			{
				return false;
			}
		}
		return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		se.insert(mp(x[i],y[i]));
		ma[mp(x[i],y[i])] = i;
	}
	set<int>ok;
	for(int i=0;i<n;i++)
	{
		if(check(x[i],y[i])) ok.insert(i);
	}
	for(int i=0;i<n;i++)
	{
		int q;
		if(i%2 == 0)
		{
			set<int>::iterator it = ok.end();
			it--;
			q = *it;
		}
		else
		{
			q = *ok.begin();
		}
		ok.erase(ok.find(q)); se.erase(se.find(mp(x[q],y[q])));
		res.pb(q);
		if(se.find(mp(x[q]-1,y[q]-1)) != se.end())
		{
			if(check(x[q]-1,y[q]-1)) ok.insert(ma[mp(x[q]-1,y[q]-1)]);
		}
		if(se.find(mp(x[q],y[q]-1)) != se.end())
		{
			if(check(x[q],y[q]-1)) ok.insert(ma[mp(x[q],y[q]-1)]);
		}
		if(se.find(mp(x[q]+1,y[q]-1)) != se.end())
		{
			if(check(x[q]+1,y[q]-1)) ok.insert(ma[mp(x[q]+1,y[q]-1)]);
		}
		if(se.find(mp(x[q]-2,y[q])) != se.end())
		{
			if(!check(x[q]-2,y[q]) && ok.find(ma[mp(x[q]-2,y[q])]) != ok.end())
			{
				ok.erase(ok.find(ma[mp(x[q]-2,y[q])]));
			}
		}
		if(se.find(mp(x[q]-1,y[q])) != se.end())
		{
			if(!check(x[q]-1,y[q]) && ok.find(ma[mp(x[q]-1,y[q])]) != ok.end())
			{
				ok.erase(ok.find(ma[mp(x[q]-1,y[q])]));
			}
		}
		if(se.find(mp(x[q]+1,y[q])) != se.end())
		{
			if(!check(x[q]+1,y[q]) && ok.find(ma[mp(x[q]+1,y[q])]) != ok.end())
			{
				ok.erase(ok.find(ma[mp(x[q]+1,y[q])]));
			}
		}
		if(se.find(mp(x[q]+2,y[q])) != se.end())
		{
			if(!check(x[q]+2,y[q]) && ok.find(ma[mp(x[q]+2,y[q])]) != ok.end())
			{
				ok.erase(ok.find(ma[mp(x[q]+2,y[q])]));
			}
		}
	}
	mul[0] = 1LL;
	for(int i=1;i<=100000;i++) mul[i] = mul[i-1]*(ll)n%mod;
	ll ret = 0;
	for(int i=0;i<res.size();i++)
	{
		ret += (res[i]*1LL*mul[res.size()-1-i]);
		ret %= mod;
	}
	cout << ret << endl;
}