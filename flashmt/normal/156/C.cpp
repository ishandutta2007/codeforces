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
#define base 1000000007
using namespace std;

int f[111][2700];

int main()
{
	f[0][0]=1;
	fr(i,1,100)
		fr(j,0,2600)
			fr(k,1,26)
			{
				f[i][j+k]+=f[i-1][j];
				if (f[i][j+k]>=base) f[i][j+k]-=base;
			}
	
	int test;
	string s;
	cin >> test;
	while (test--)
	{
		cin >> s;
		int sum=0;
		rep(i,sz(s)) sum+=s[i]-'a'+1;
		int ans=f[sz(s)][sum]-1;
		if (ans<0) ans++;
		cout << ans << endl;
	}
}