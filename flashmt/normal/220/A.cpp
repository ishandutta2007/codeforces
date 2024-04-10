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

int n,a[100100],b[100100];

int main()
{
	cin >> n;
	rep(i,n) cin >> a[i], b[i]=a[i];
	sort(b,b+n);
	
	vector <int> c;
	rep(i,n)
		if (a[i]!=b[i]) c.pb(i);
		
	if (sz(c)==1 || sz(c)>2) puts("NO");
	else
	{
		if (sz(c)==2)
		{
			if (a[c[0]]==b[c[1]] && a[c[1]]==b[c[0]]) puts("YES");
			else puts("NO");
		}
		else puts("YES");
	}
}