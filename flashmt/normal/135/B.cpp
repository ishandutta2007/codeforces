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

int n,a[8],b[8];

int dist(pii i,pii j)
{
	return (i.fi-j.fi)*(i.fi-j.fi)+(i.se-j.se)*(i.se-j.se);
}

int perpen(pii i,pii j,pii k)
{
	int a=i.se-j.se,b=j.fi-i.fi,aa=j.se-k.se,bb=k.fi-j.fi;
	return a*aa+b*bb==0;
}

int valid(vector < pii > s,vector < pii > r,int i,int j,int k,int ii,int jj,int kk)
{
	vector < pii > a,b;
	a.pb(s[0]); a.pb(s[i]); a.pb(s[j]); a.pb(s[k]);
	b.pb(r[0]); b.pb(r[ii]); b.pb(r[jj]); b.pb(r[kk]);
	long long S=0,ss=0;
	rep(i,3)
	{
		int x=dist(a[i],a[i+1]),y=dist(a[i+1],a[(i+2)&3]);
		if (x!=y) return 0;
	}
	rep(i,4)
	{
		int ii=(i+1)&3;
		S+=(a[i].fi-a[ii].fi)*(a[i].se+a[ii].se);
	}
	if (S==0) return 0;
	rep(i,3)
		if (!perpen(a[i],a[i+1],a[(i+2)&3])) return 0;
	if (dist(b[0],b[1])!=dist(b[2],b[3])) return 0;
	if (dist(b[1],b[2])!=dist(b[0],b[3])) return 0;
	rep(i,3)
		if (!perpen(b[i],b[i+1],b[(i+2)&3])) return 0;
	rep(i,4)
	{
		int ii=(i+1)&3;
		ss+=(b[i].fi-b[ii].fi)*(b[i].se+b[ii].se);
	}
	if (ss==0) return 0;
	return 1;
}

int ok(int s)
{
	vector < pii > square,rect;
	rep(i,8)
		if ((s>>i)&1) square.pb(mp(a[i],b[i]));
		else rect.pb(mp(a[i],b[i]));
	fr(i,1,3)
		fr(j,1,3)
			fr(k,1,3)
				if (i!=j && j!=k && i!=k)
					fr(ii,1,3)
						fr(jj,1,3)
							fr(kk,1,3)
								if (ii!=jj && jj!=kk && kk!=ii)
									if (valid(square,rect,i,j,k,ii,jj,kk))
										return 1;
	return 0;
}

int main()
{
	rep(i,8) cin >> a[i] >> b[i];
	rep(s,1<<8)
	{
		int t=0;
		rep(i,8) t+=((s>>i)&1);
		if (t!=4) continue;
		if (ok(s)) 
		{
			puts("YES");
			rep(i,8) if ((s>>i)&1) cout << 1+i << ' ';
			puts("");
			rep(i,8) if (!((s>>i)&1)) cout << 1+i << ' ';
			puts("");
			return 0;
		}
	}
	puts("NO");
}