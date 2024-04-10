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
#define delta 200100
using namespace std;

int n,sum,f[800800],ans,cnt;
string s;

int vowel(char c)
{
	if (c<='Z') c+='a'-'A';
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

void add(int x,int val)
{
	x+=delta;
	while (x<=2*n+delta) 
	{
		if (f[x]<=val) return;
		f[x]=val;
		x+=x&-x;
	} 
}

int get(int x)
{
	x+=delta;
	int r=n+1;
	while (x) r=min(r,f[x]), x-=x&-x;
	return r;
}

int main()
{
	cin >> s;
	n=sz(s);
	s="*"+s;
	fr(i,1,2*n+delta) f[i]=n+1;
	add(0,0);
	fr(i,1,n) 
	{
		sum+=!vowel(s[i]);
		int x=get(sum*3-i);
		if (i-x==ans) cnt++;
		else
			if (i-x>ans) ans=i-x, cnt=1;
		add(sum*3-i,i);
	}
	if (!ans) puts("No solution");
	else cout << ans << ' ' << cnt << endl;
}