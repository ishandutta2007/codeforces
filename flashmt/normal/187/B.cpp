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

int n,m,r,a[66][66][66],f[66][66][66];

int main()
{
	cin >> n >> m >> r;
	fr(i,0,n) fr(j,1,n) fr(k,1,n) f[i][j][k]=oo;
	fr(i,1,m) 
	{
		fr(j,1,n) fr(k,1,n) cin >> a[i][j][k];
		fr(p,1,n) fr(j,1,n) fr(k,1,n) a[i][j][k]=min(a[i][j][k],a[i][j][p]+a[i][p][k]);
		fr(j,1,n) fr(k,1,n) f[0][j][k]=min(f[0][j][k],a[i][j][k]);
	}
	fr(i,1,n)
		fr(j,1,n)
			fr(k,1,n)
				fr(p,1,n)
					f[i][j][p]=min(f[i][j][p],f[i-1][j][k]+f[0][k][p]);
	
	while (r--)
	{
		int s,t,k;
		scanf("%d%d%d",&s,&t,&k);
		k=min(k,n);
		printf("%d\n",f[k][s][t]);
	}
}