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

int n,a[100100][30],b[30],ans;

int isGood(int r,int l)
{
	if (l<0) return 0;
	rep(i,26)
		if (b[i]<a[r][i]-a[l][i]) return 0;
	return 1;
}

int main()
{
	string s,t;
	cin >> s >> t;
	rep(i,sz(t)) b[t[i]-'a']++;
	rep(i,sz(s)) 
	{
		rep(j,26)
			a[i+1][j]=a[i][j]+(s[i]-j=='a');
		ans+=isGood(i+1,i+1-sz(t));
	}
	cout << ans << endl;
}