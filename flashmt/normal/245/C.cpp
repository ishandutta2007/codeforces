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

int n,a[111],ans;

void go(int x)
{
	if (x*2+1>n) return;
	go(x*2);
	go(x*2+1);
	ans+=max(a[x*2],a[x*2+1]);
	a[x]=max(0,a[x]-max(a[x*2],a[x*2+1]));
	a[x*2]=a[x*2+1]=0;
	if (x==1) ans+=a[x], a[x]=0;
}

int main()
{
	cin >> n;
	fr(i,1,n) cin >> a[i];
	go(1);
	fr(i,1,n)
		if (a[i])
		{
			puts("-1");
			return 0;
		}
	cout << ans << endl;
}