//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
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
#define s (1<<18)
vector<P1>tate,yoko;
int seg[s*2];
void init(){ memset(seg,0,sizeof(seg));}
void update(int pos,int z)
{
	pos+=s-1;
	seg[pos]+=z;
	while(pos>0)
	{
		pos=(pos-1)/2;
		seg[pos]=seg[pos*2+1]+seg[pos*2+2];
	}
}
int get(int a,int b,int k,int l,int r)
{
	if(r<a || b<l) return 0;
	if(a<=l && r<=b) return seg[k];
	int lko=get(a,b,k*2+1,l,(l+r)/2);
	int rko=get(a,b,k*2+2,(l+r)/2+1,r);
	return lko+rko;
}
bool ok(int gen)
{
	init();
	vector<P1>newtate,newyoko;
	vector<int>x,y;
	for(int i=0;i<tate.size();i++)
	{
		if(tate[i].fi>=2*gen)
		{
			newtate.pb(mp(tate[i].fi-2*gen,mp(tate[i].sc.fi,tate[i].sc.sc+gen)));
			x.pb(tate[i].sc.fi);
			y.pb(tate[i].sc.sc+gen);
			y.pb(tate[i].sc.sc+tate[i].fi-gen);
		}
	}
	for(int i=0;i<yoko.size();i++)
	{
		if(yoko[i].fi>=2*gen)
		{
			newyoko.pb(mp(yoko[i].fi-2*gen,mp(yoko[i].sc.fi+gen,yoko[i].sc.sc)));
			x.pb(yoko[i].sc.fi+gen);
			y.pb(yoko[i].sc.sc);
			x.pb(yoko[i].sc.fi+yoko[i].fi-gen);
		}
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	y.erase(unique(y.begin(),y.end()),y.end());
	vector<int>in[150005];
	vector<int>out[150005];
	vector<P>ty[150005];
	for(int i=0;i<newyoko.size();i++)
	{
		int le=lower_bound(x.begin(),x.end(),newyoko[i].sc.fi)-x.begin();
		int ri=lower_bound(x.begin(),x.end(),newyoko[i].sc.fi+newyoko[i].fi)-x.begin();
		int t=lower_bound(y.begin(),y.end(),newyoko[i].sc.sc)-y.begin();
		in[le].pb(t);
		out[ri].pb(t);
	}
	for(int i=0;i<newtate.size();i++)
	{
		int down=lower_bound(y.begin(),y.end(),newtate[i].sc.sc)-y.begin();
		int up=lower_bound(y.begin(),y.end(),newtate[i].sc.sc+newtate[i].fi)-y.begin();
		int t=lower_bound(x.begin(),x.end(),newtate[i].sc.fi)-x.begin();
		ty[t].pb(mp(down,up));
	}
	for(int i=0;i<x.size();i++)
	{
		for(int j=0;j<in[i].size();j++)
		{
			update(in[i][j],1);
		}
		for(int j=0;j<ty[i].size();j++)
		{
			int a=ty[i][j].fi;
			int b=ty[i][j].sc;
			if(get(a,b,0,0,s-1))
			{
				return ok;
			}
		}
		for(int j=0;j<out[i].size();j++)
		{
			update(out[i][j],-1);
		}
	}
	return false;
}
int main()
{
	srand((unsigned int)time(NULL));
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		int a,b,ln;
		cin >> a >> b >> ln;
		tate.pb(mp(ln,mp(a,b)));
	}
	for(int i=0;i<m;i++)
	{
		int a,b,ln;
		cin >> a >> b >> ln;
		yoko.pb(mp(ln,mp(a,b)));
	}
	int lb=0;
	int ub=200000005;
	//[lb,ub)
	while(ub-lb>1)
	{
		int mid=(lb+ub)>>1;
		if(ok(mid)) lb=mid;
		else ub=mid;
	}
	cout << lb << endl;
}