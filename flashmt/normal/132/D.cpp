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
#define maxN 1
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
#define oo 1000111222
using namespace std;

int n,m,len[1000100],start[1000100];
char a[1000100];
vector <int> pos,neg;

int main()
{
	int ok=0;
	scanf("%s",&a);
	n=strlen(a);
	for (int i=0;i<n;)
	{
		int j=i+1;
		while (j<n && a[j]==a[i]) j++;
		if (a[i]=='0') 
		{
			if (j-i==1) ok=i;
			else ok=0;
		}
		else
		{
			if (j-i==1) 
			{
				if (ok && sz(pos) && len[sz(pos)-1]>1) neg.pb(ok), len[sz(pos)-1]+=j-i+1;
				else pos.pb(i), len[sz(pos)-1]=1;
			}
			else
			{
				if (ok && sz(pos) && len[sz(pos)-1]>1) neg.pb(ok), len[sz(pos)-1]+=j-i+1;
				else pos.pb(i-1), len[sz(pos)-1]=j-i;
			}
			ok=0;
		} 
		i=j;
	}
	rep(i,sz(pos))
		if (len[i]>1) neg.pb(pos[i]+len[i]);
	cout << sz(pos)+sz(neg) << endl;
	rep(i,sz(pos)) printf("+2^%d\n",n-1-pos[i]);
	rep(i,sz(neg)) printf("-2^%d\n",n-1-neg[i]);
}