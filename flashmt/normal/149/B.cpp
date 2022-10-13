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

int d[70],e[70];

int valid(string a,int base,int lim)
{
	int p=1,x=0;
	repp(i,sz(a)) 
	{
		int digit=(a[i]<='9'?a[i]-'0':a[i]-'A'+10);
		if (digit>=base) return 0;
		x+=digit*p;
		p*=base;
		if (x>=lim) return 0;
	}
	return 1;
}

int infinity(string a,int d[],int lim)
{
	if (sz(a)==1)
	{
		fr(i,1,60) d[i]=valid(a,i,lim);
		return valid(a,lim,lim);
	}
	else
	{
		fr(i,1,lim) d[i]=valid(a,i,lim);
		return 0;
	}
}

int main()
{
	string a,b;
	cin >> a;
	rep(i,sz(a))
		if (a[i]==':')
		{
			b=a.substr(i+1,sz(a)-i);
			a.erase(i,sz(a)-i+1);
		}
	while (sz(a)>1 && a[0]=='0') a.erase(0,1);
	while (sz(b)>1 && b[0]=='0') b.erase(0,1);
	if (infinity(a,d,24)+infinity(b,e,60)==2)
	{
		puts("-1");
		return 0;
	}
	int haveAns=0;
	fr(i,1,60)
		if (d[i] && e[i]) cout << i << ' ', haveAns=1;
	if (!haveAns) puts("0");
}