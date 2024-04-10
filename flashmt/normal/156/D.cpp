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
using namespace std;

int need,n,m,base,d[100100],cnt[100100];
long long ans;

int get(int x)
{
	if (d[x]!=x) d[x]=get(d[x]);
	return d[x];
}

int main()
{
	cin >> n >> m >> base;
	fr(i,1,n) d[i]=i;
	need=n-1;
	while (m--) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=get(x); y=get(y);
		if (x!=y) d[x]=y, need--;
	}
	fr(i,1,n) cnt[get(i)]++;
	
	ans=1%base;
	
	if (need)
	{
		fr(i,1,n)
			if (cnt[i]) ans=ans*cnt[i]%base;
		rep(i,need-1) ans=ans*n%base;		
	}
	cout << ans << endl;
}