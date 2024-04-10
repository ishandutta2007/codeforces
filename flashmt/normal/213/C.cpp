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
#define maxN 1
using namespace std;

int n,a[333][333],f[2][333][333],l[666],r[666];

int main()
{
	int z=0;
	cin >> n;
	rep(i,n) rep(j,n) scanf("%d",a[i]+j);
	rep(j,n) rep(k,n) f[0][j][k]=-oo;
	f[0][0][0]=a[0][0];
	
	fr(i,0,n*2-2)
	{
		l[i]=i<n?0:i-n+1;
		r[i]=i<n?i:n-1;
	}
	
	fr(i,0,n*2-3)
	{
		z^=1;
		rep(j,n) rep(k,n) f[z][j][k]=-oo;
		fr(j,l[i],r[i])
			fr(k,j,r[i])
				if (f[1-z][j][k]>-oo)
					fr(jj,j,j+1)
						if (jj>=l[i+1] && jj<=r[i+1])
							fr(kk,k,k+1)
								if (kk>=l[i+1] && kk<=r[i+1])
								{
									int add=a[jj][i+1-jj]+a[kk][i+1-kk];
									if (jj==kk) add/=2;
									f[z][jj][kk]=max(f[z][jj][kk],f[1-z][j][k]+add);
								}
	}
	
	cout << f[z][n-1][n-1] << endl;
}