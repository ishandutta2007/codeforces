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

int n,m,d[256];

void att(int i,string s,string t,int greater)
{
	if (greater)
	{
		fr(k,'a','z')
			rep(j,d[k])
				s+=char(k);
		cout << s << endl;
		exit(0);
	}
	if (i==n) return;
	if (i<m)
	{
		if (d[t[i]]) 
		{
			d[t[i]]--;
			att(i+1,s+t[i],t,0);
			d[t[i]]++;
		}
		fr(j,t[i]+1,'z')
			if (d[j])
			{
				d[j]--;
				att(i+1,s+char(j),t,1);
				d[j]++;
			}
	}
	else att(i,s,t,1);
}

int main()
{
	string s,t;
	cin >> s >> t;
	n=sz(s); m=sz(t);
	rep(i,n) d[s[i]]++;
	s="";
	att(0,s,t,0);
	puts("-1");
}