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
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000111222
#define maxN 1
using namespace std;

char st[100100];
int pos[100100],ans,last,L,R=-1;
vector < pii > r;

int main()
{
	string s;
	cin >> s;
	rep(i,sz(s))
	{
		if (s[i]=='(' || s[i]=='[') st[++last]=s[i], pos[last]=i;
		else
		{
			char c=(s[i]==')'?'(':'[');
			if (!last || c!=st[last]) last=0;
			else r.pb(mp(pos[last--],i));
		}
	}
	
	if (!r.empty())
	{
		sort(all(r));
		int end=r[0].se,square=0,start=r[0].fi;
		fr(i,r[0].fi,r[0].se) square+=s[i]=='[';
		if (square>ans) ans=square, L=start, R=end;
		
		fr(i,1,sz(r)-1)
			if (r[i].se>end) 
			{
				int cnt=0;
				fr(j,r[i].fi,r[i].se) cnt+=s[j]=='[';
				
				if (r[i].fi==end+1) square+=cnt;
				else start=r[i].fi, square=cnt;
				end=r[i].se;
				
				if (square>ans) ans=square, L=start, R=end;
			}
		
		if (square>ans) ans=square, L=start, R=end;
	}
	
	cout << ans << endl;
	fr(i,L,R) cout << s[i];
	cout << endl;
}