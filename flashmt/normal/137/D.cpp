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
#define maxN 1
using namespace std;

int n,k,f[555][555],tr[555][555],c[555][555],ans=oo;
string a;
vector < pii > r;

void trace(int n,int k)
{
	if (!n)
	{
		int start=1;
		while (!r.empty())
		{
			pii u=r[sz(r)-1];
			r.pop_back();
			if (!start) cout << '+';
			else start=0;
			int l=u.fi,r=u.se;
			fr(i,l,r)
				if (i<=(l+r)/2) cout << a[l+r-i];
				else cout << a[i];
		}
		return;
	}
	int x=tr[n][k];
	r.push_back(make_pair(x+1,n));
	trace(x,k-1);
}

int main()
{
	cin >> a;
	n=sz(a);
	a="="+a;
	cin >> k;
	fr(i,1,n-1) c[i][i+1]=a[i]!=a[i+1];
	fr(l,3,n)
		fr(i,1,n-l+1)
		{
			int j=i+l-1;
			c[i][j]=(a[i]!=a[j])+c[i+1][j-1];
		}
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	fr(i,0,n-1)
		fr(j,0,k-1)
			if (f[i][j]>=0)
				fr(ii,i+1,n)
					if (f[ii][j+1]<0 || f[ii][j+1]>f[i][j]+c[i+1][ii])
						f[ii][j+1]=f[i][j]+c[i+1][ii], tr[ii][j+1]=i;
	fr(i,0,k) 
		if (f[n][i]>=0) ans=min(ans,f[n][i]);
	cout << ans << endl;
	fr(i,0,k)
		if (ans==f[n][i])
		{
			trace(n,i);
			return 0;
		}
}