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

int f[500],n,k,m;

int main()
{
	cin >> n >> k;
	f[0]=1;
	while (1)
	{
		long long x=0;
		frr(i,m,max(0,m-k+1)) x+=f[i];
		if (x>1000000000) break;
		f[++m]=x;
	}

	vector <int> ans;
	frr(i,m,0)
		if (n>=f[i]) ans.pb(f[i]), n-=f[i];
	if (sz(ans)==1) ans.pb(0);
	cout << sz(ans) << endl;
	rep(i,sz(ans)) cout << ans[i] << ' ';
	puts("");
}