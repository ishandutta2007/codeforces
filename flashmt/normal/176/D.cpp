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

int n,m,l[2020],g[2020][26],b[2020];
char s[1000100];
vector <int> a[2020][26];
vector <int>::iterator it;
pair <int,int> f[2020][2020];

int main()
{
	cin >> n;
	fr(i,1,n)
	{
		scanf("%s",s);
		l[i]=strlen(s);
		rep(j,l[i])
		{
			int ch=s[j]-'a';
			a[i][ch].pb(j);
		}
	}
	
	cin >> m;
	fr(i,1,m) cin >> b[i];
	
	string t;
	cin >> t;
	int k=sz(t);
	t=' '+t;
	
	fr(i,1,m)
		rep(ch,26)
			fr(j,i,m)
				if (!a[b[j]][ch].empty())
				{
					g[i][ch]=j; break;
				}
	
	fr(i,1,k)
	{
		f[1][i]=mp(0,0);
		int ch=t[i]-'a';
		fr(j,1,m)
			if (!a[b[j]][ch].empty())
			{
				f[1][i]=mp(j,a[b[j]][ch][0]);
				break;
			}
	}
	
	fr(i,2,k)
	{
		int ok=0,x,y;
		fr(j,i-1,k-1)
		{
			int ch=t[j+1]-'a';
			if (f[i-1][j].fi && (!ok || (ok && mp(x,y)>f[i-1][j])))
				x=f[i-1][j].fi, y=f[i-1][j].se, ok=1;
			
			if (!ok) continue;	
			int found=0;
			if (!a[b[x]][ch].empty())
			{
				it=upper_bound(a[b[x]][ch].begin(),a[b[x]][ch].end(),y);
				if (it!=a[b[x]][ch].end())
				{
					f[i][j+1]=mp(x,(*it));
					found=1;
				}
			}
			
			if (!found && x<m && g[x+1][ch]) 
				f[i][j+1]=mp(g[x+1][ch],a[b[g[x+1][ch]]][ch][0]);
		}
		}
		
	int ans=0;
	fr(i,1,k)
		fr(j,1,k)
			if (f[i][j].fi)
			{
				ans=i;
				break;
			}
	
	cout << ans << endl;
}