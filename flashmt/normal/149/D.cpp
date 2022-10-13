#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define base 1000000007
using namespace std;
const int dl[]={0,0,0,1,1,1,2,2,2};
const int dr[]={0,1,2,0,1,2,0,1,2};
const int b[]={1,2,3,6};

int n,st[1000],last;
long long f[1000][9];
vector <int> a[1000];

int merge(int j,int k,int withPar)
{
	if (!withPar)
	{
		if (dr[j] && dl[k] && dr[j]==dl[k]) return -1;
		rep(i,9)
			if (dl[i]==dl[j] && dr[i]==dr[k]) return i;
		return -1;
	}
	else
	{
		if (dl[j] && dl[k] && dl[j]==dl[k]) return -1;
		if (dr[j] && dr[k] && dr[j]==dr[k]) return -1;
		return j;
	}	
}

void visit(int x)
{
	if (a[x].empty())
	{
		rep(i,4) f[x][b[i]]=1;
		return;
	}
	
	long long g[9],h[9];
	rep(i,sz(a[x])) 
	{
		int y=a[x][i];
		visit(y);
		
		if (!i)
		{
			rep(j,9) h[j]=f[y][j];
			continue;
		}
		
		rep(j,9) g[j]=h[j], h[j]=0;
		rep(j,9)
			rep(k,9)
			{
				int p=merge(j,k,0);
				if (p>=0)
				{
					h[p]+=g[j]*f[y][k];
					h[p]%=base;
				}
			}
	}

	if (!x) 
		rep(i,9) f[x][i]=h[i];
	else
		rep(j,4) 
			rep(k,9)
				if (merge(b[j],k,1)>=0)
					f[x][b[j]]+=h[k], f[x][b[j]]%=base;
}

int main()
{
	string s;
	cin >> s;
	rep(i,sz(s))
		if (s[i]=='(')
		{
			a[st[last]].pb(++n);
			st[++last]=n;
		}
		else last--;
	visit(0);
	long long ans=0;
	rep(i,9) ans+=f[0][i];
	cout << ans%base << endl;
}