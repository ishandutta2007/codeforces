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
#define maxN 1
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
#define oo 1000111222
#define z 101
using namespace std;

int n,m,f[111][55][211];
string s;

int main()
{
	cin >> s >> m;
	n=sz(s);
	f[0][0][0+z]=1;
	fr(i,0,n-1)
		fr(j,0,m)
			fr(k,-100,100)
				if (f[i][j][k+z])
				{
					if (s[i]=='F') f[i+1][j][k+z+1]=f[i+1][j+1][-k+z]=1;
					else f[i+1][j][-k+z]=f[i+1][j+1][k+z+1]=1;
				}
	int ans=0;
	for (int j=m;j>=0;j-=2) 
		fr(k,-100,100) 
			if (f[n][j][k+z]) ans=max(ans,abs(k));
	cout << ans << endl;
}