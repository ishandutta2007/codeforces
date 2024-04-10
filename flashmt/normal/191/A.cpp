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

int n,ans,a[30][30][20],f[30][30],g[30][30];

int main()
{
	char s[20];
	cin >> n;

	rep(i,n)
	{
		scanf("%s",s);
		int l=strlen(s),x=s[0]-'a',y=s[l-1]-'a';
		
		rep(j,26) g[j][x]=f[j][x];
		
		rep(j,26)
			if (g[j][x]) f[j][y]=max(f[j][y],g[j][x]+l);
			
		f[x][y]=max(f[x][y],l);
	}
	
	int ans=0;
	rep(i,26) ans=max(ans,f[i][i]);
	cout << ans << endl;
}