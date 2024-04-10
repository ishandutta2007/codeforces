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

int n,m,l[200200],r[200200];
string a,b;
vector <int> c[26],d[26];

int main()
{
	cin >> a >> b;
	m=sz(a); n=sz(b);
	rep(i,m) c[a[i]-'a'].pb(i);
	rep(i,26) d[i].resize(sz(c[i])+1,0);
	
	int last=-1;
	rep(i,n)
	{
		int ch=b[i]-'a';
		int x=upper_bound(all(c[ch]),last)-c[ch].begin();
		if (x==sz(c[ch]))
		{
			puts("No"); return 0;
		}
		last=c[ch][x];
		d[ch][x]++;
	}
	
	last=m+1;
	repp(i,n)
	{
		int ch=b[i]-'a';
		int x=lower_bound(all(c[ch]),last)-c[ch].begin();
		d[ch][x]--;
		if (x) last=c[ch][x-1];
		else break;
	}
	
	rep(i,26)
	{
		int cnt=0;
		rep(j,sz(c[i]))
		{
			cnt+=d[i][j];
			if (!cnt) 
			{
				puts("No"); return 0;
			}
		}
	}
	puts("Yes");
}