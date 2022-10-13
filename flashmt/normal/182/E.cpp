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
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define base 1000000007 
using namespace std;

int n,L,a[111],b[111],f[3333][111][2];

int main()
{
	cin >> n >> L;
	fr(i,1,n) cin >> a[i] >> b[i];
	
	fr(i,1,n) 
	{
		f[a[i]][i][0]=1;
		if (b[i]!=a[i]) f[b[i]][i][1]=1;
	}
	
	fr(i,1,L-1)
		fr(j,1,n)
			rep(k,2)
				if (f[i][j][k])
					fr(jj,1,n)
						if (j!=jj)
						{
							int lastWidth=(k?a[j]:b[j]);
							if (a[jj]==lastWidth)
								f[i+a[jj]][jj][0]+=f[i][j][k], f[i+a[jj]][jj][0]%=base;
							if (b[jj]==lastWidth && b[jj]!=a[jj])
								f[i+b[jj]][jj][1]+=f[i][j][k], f[i+b[jj]][jj][1]%=base;
						}
						
	int ans=0;
	fr(i,1,n)
		rep(j,2)
			ans+=f[L][i][j], ans%=base;
	cout << ans << endl;
}