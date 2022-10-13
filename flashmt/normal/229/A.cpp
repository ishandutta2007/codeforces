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

int f[10100],a[10010];

int main()
{
	int m,n;
	cin >> m >> n;
	rep(i,m) 
	{
		string s;
		int cnt=0;
		cin >> s;
		rep(j,n)
			if (s[j]=='1') a[cnt++]=j;
		if (!cnt)
		{
			puts("-1"); return 0;
		}
		
		int k=0;
		rep(j,n)
		{
			while (k<cnt && a[k]<j) k++;
			int v;
			if (k<cnt) v=a[k]-j; 
			else v=a[0]+n-j;
			if (k) v=min(v,j-a[k-1]);
			else v=min(v,j+n-a[cnt-1]);
			f[j]+=v;
		}
	}
	
	int ans=oo;
	rep(j,n) ans=min(ans,f[j]);
	cout << ans << endl;	
}