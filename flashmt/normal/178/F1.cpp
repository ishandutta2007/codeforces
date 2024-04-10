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

int n,k,f[22][22];
string a[22];

int calc(string s,string t)
{
	int ans=0;
	rep(i,min(sz(s),sz(t)))
		if (s[i]==t[i]) ans=i+1;
		else break;
	return ans;
}

int main()
{
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	rep(i,n)
		fr(j,i+1,n-1)
			f[i][j]=f[j][i]=calc(a[i],a[j]);
	
	int ans=0;
	rep(s,1<<n)
	{
		vector <int> b;
		int sum=0;
		rep(i,n)
			if (s>>i&1)
			{
				rep(j,sz(b)) sum+=f[i][b[j]];
				b.pb(i);
			}
		if (sz(b)==k) ans=max(ans,sum);
	}
	cout << ans << endl;
}