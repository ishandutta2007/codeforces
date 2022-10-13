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

string a,b;

int check(int x)
{
	rep(i,x)
		if (a[i]!=b[i]) return 0;
	fr(i,x,sz(a)-1)
		if (a[i]!=a[i-x]) return 0;
	fr(i,x,sz(b)-1)
		if (b[i]!=b[i-x]) return 0;
	return 1;
}

int main()
{
	int ans=0;
	cin >> a >> b;
	for (int i=1;i<=sz(a) && i<=sz(b);i++) 
		if (sz(a)%i==0 && sz(b)%i==0) ans+=check(i);
	cout << ans << endl;
}