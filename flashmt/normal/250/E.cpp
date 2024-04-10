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

int m,n;
char a[111][10101];

int main()
{
	cin >> m >> n;
	rep(i,m) scanf("%s",a[i]);
	
	int j=0,z=1;
	long long ans=0;
	rep(i,m-1)
	{
		int l=j,r=j,cnt=0;
		while (cnt<2)
		{
			if (a[i+1][j]=='.') 
			{
				ans++; break;
			}
			
			if (z==1)
			{
				if (r+1>=n || a[i][r+1]=='#') z=-1, ans+=(r-j)*2+1, cnt++;
				else
				{
					cnt=0;
					if (a[i][r+1]=='+') z=-1, ans+=(r-j)*2+1, a[i][r+1]='.';
					else ans+=(r+1-j), j=++r;
				}
			}
			else
			{
				if (l-1<0 || a[i][l-1]=='#') z=1, ans+=(j-l)*2+1, cnt++;
				else
				{
					cnt=0;
					if (a[i][l-1]=='+') z=1, ans+=(j-l)*2+1, a[i][l-1]='.';
					else ans+=(j-l+1), j=--l;
				}
			}
		}

		if (cnt==2)
		{
			puts("Never");
			return 0;
		}
	}
	
	cout << ans << endl;
}