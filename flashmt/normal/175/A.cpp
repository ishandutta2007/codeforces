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

long long conv(string s)
{
	if (s=="0") return 0;
	if (s[0]=='0') return -oo;
	if (sz(s)>7) return -oo;
	long long x=0;
	rep(i,sz(s)) x=x*10+s[i]-'0';
	if (x>1000000) return -oo;
	return x;
}

int main()
{
	string s;
	cin >> s;
	int n=sz(s);
	long long ans=-1;
	fr(i,1,n-1)
		fr(j,i+1,n-1)
		{
			string t="",u="",v="";
			rep(jj,i) t+=s[jj];
			fr(jj,i,j-1) u+=s[jj];
			fr(jj,j,n-1) v+=s[jj];
			long long score=conv(t)+conv(u)+conv(v);
			ans=max(ans,score);
		}
	cout << ans << endl;
}