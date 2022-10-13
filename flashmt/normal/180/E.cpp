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

int n,m,k,ans;
vector <int> a[100100];

int main()
{
	int c;
	cin >> n >> m >> k;
	rep(i,n) cin >> c, a[c].pb(i);
	fr(c,1,m)
		for (int i=0,j=0;i<sz(a[c]);i++)
		{
			while (a[c][i]-a[c][j]-i+j>k) j++;
			ans=max(ans,i-j+1);
		}
	cout << ans << endl;
}