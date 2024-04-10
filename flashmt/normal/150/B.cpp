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

int n,d[2222],m,k;
set <int> s;

int get(int x)
{
	if (d[x]!=x) d[x]=get(d[x]);
	return d[x];
}

int main()
{
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++) d[i]=i;
	for (int r=k;r<=n;r++)
		for (int i=r-k+1,j=r;i<j;i++,j--)
		{
			int x=get(i),y=get(j);
			if (x!=y) d[x]=y;
		}
	for (int i=1;i<=n;i++) s.insert(get(i));

	long long ans=1;
	for (int i=0;i<sz(s);i++) ans=ans*m%base;
	cout << ans << endl;
}