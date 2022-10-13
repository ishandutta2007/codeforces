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
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000111222
#define maxN 1
using namespace std;

int n,q,a[100100],f[500][100100],d[100100];
vector <int> can;

int main()
{
	cin >> n >> q;
	fr(i,1,n) 
	{
		scanf("%d",a+i);
		if (a[i]<=n) d[a[i]]++;
	}

	fr(i,1,n)
		if (d[i]>=i) can.pb(i);
		
	rep(i,sz(can))
		fr(j,1,n)
			f[i][j]=f[i][j-1]+(a[j]==can[i]);
		
	while (q--)
	{
		int ans=0,l,r;
		scanf("%d%d",&l,&r);
		rep(i,sz(can)) ans+=f[i][r]==f[i][l-1]+can[i];
		printf("%d\n",ans);
	}
}