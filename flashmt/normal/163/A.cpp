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
#define z 1000000007 
using namespace std;

int f[5050][5050],ans;

int main()
{
	string s,t;
	int m,n;
	cin >> s >> t;
	m=sz(s); n=sz(t);
	s="-"+s; t="-"+t;
	frr(i,m,1)
	{
		frr(j,n,1)
		{
			if (s[i]==t[j]) f[i][j]=(f[i][j]+f[i+1][j+1]+1)%z;
			f[i][j]=(f[i][j]+f[i][j+1])%z;
		}
		ans+=f[i][1];
		ans%=z;
	}
	cout << ans << endl;
}