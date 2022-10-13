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
#define N 2000100
using namespace std;

int m,n,a[N],b[N],d[N],ans=1,pos[N];

int between(int x,int y,int z)
{
	if (z<y) return x<z || x>y;
	return x>y && x<z;
}

int main()
{
	reset(d,-1);
	cin >> m >> n;
	rep(i,m) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]), d[b[i]]=i;
	int M=0;
	rep(i,m)
		if (d[a[i]]>=0) a[M]=a[i], pos[M++]=i;
	swap(m,M);
	if (!m)
	{
		puts("0"); return 0;
	}
	
	rep(i,m) a[m+i]=a[i], pos[m+i]=pos[i]+M;
	
	int x=1,bor=0;
	fr(i,1,m*2-1)
		if (pos[i]==pos[i-1]+1)
		{
			x++;
			while (x>2 && !between(d[a[i]],d[a[i-1]],d[a[bor]])) bor++, x--;
			ans=max(ans,x);
		}
		else x=1, bor=i;
	cout << min(m,ans) << endl;
}