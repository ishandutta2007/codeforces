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

int main()
{
	string s,u;
	cin >> s >> u;
	int ans=sz(u);
	rep(i,sz(u)-1) s="."+s+".";
	rep(i,sz(s))
		if (i+sz(u)<=sz(s))
		{
			int x=0;
			rep(j,sz(u)) x+=(s[i+j]!=u[j]);
			ans=min(ans,x);
		}
	cout << ans << endl;
}