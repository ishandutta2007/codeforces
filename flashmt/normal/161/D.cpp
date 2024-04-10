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

int n,k,f[50050][505];
vector <int> a[100100];
long long ans;

void visit(int x,int par)
{
	f[x][0]=1;
	rep(i,sz(a[x]))
	{
		int y=a[x][i];
		if (y==par) continue;
		visit(y,x);
		fr(j,0,k-1) ans+=1LL*f[y][j]*f[x][k-1-j];
		fr(j,0,k-1) f[x][j+1]+=f[y][j];
	}
}

int main()
{
	int x,y;
	cin >> n >> k;
	rep(i,n-1) cin >> x >> y, a[x].pb(y), a[y].pb(x);
	visit(1,0);
	cout << ans << endl;
}