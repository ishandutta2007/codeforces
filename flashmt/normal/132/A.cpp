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

int n,last;
string s;
int main()
{
	getline(cin,s);
	rep(i,sz(s))
	{
		int x=int(s[i]);
		vector <int> a;
		fr(j,0,7) a.pb(x%2), x/=2;
		fr(j,0,7) x=x*2+a[j];
		int ans=last-x;
		if (ans<0) ans+=256;
		cout << ans << endl;
		last=x;
	}
}