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

int n,a[20],s,per,ans[4][4],canPair[20][20],app[20];
vector <int> mask;
map <int,int> d,e;

void output()
{
	rep(i,n) 
	{
		rep(j,n) cout << ans[i][j] << ' ';
		puts("");
	}
	exit(0);
}

int checkDiagonal()
{
	int cur=0;
	rep(i,n) cur+=ans[i][i];
	if (cur!=per) return 0;
	cur=0;
	rep(i,n) cur+=ans[i][n-1-i];
	return cur==per;
}

void go(int c1,int c2,int c3,int c4)
{
	d=e;
	ans[0][0]=a[c1]; ans[n-1][n-1]=a[c2];
	ans[0][n-1]=a[c3]; ans[n-1][0]=a[c4];
	d[a[c1]]--; d[a[c2]]--; d[a[c3]]--; d[a[c4]]--;
	if (n==3)
	{
		int x=per-a[c1]-a[c3];
		if (!d.count(x) || !d[x]) return;
		d[x]--; ans[0][1]=x;
		
		x=per-a[c1]-a[c4];
		if (!d.count(x) || !d[x]) return;
		d[x]--; ans[1][0]=x;
		
		x=per-a[c2]-a[c3];
		if (!d.count(x) || !d[x]) return;
		d[x]--; ans[1][2]=x;
		
		x=per-a[c2]-a[c4];
		if (!d.count(x) || !d[x]) return;
		d[x]--; ans[2][1]=x;
		
		x=per-ans[0][1]-ans[2][1];
		if (!d.count(x) || !d[x]) return;
		d[x]--; ans[1][1]=x;
		
		if (checkDiagonal()) output();
	}
}

int main()
{
	cin >> n;
	rep(i,n*n) cin >> a[i], s+=a[i], e[a[i]]++;
	per=s/n;
	cout << per << endl;
	
	if (n==1) 
	{
		cout << a[0] << endl;
		return 0;
	}
	
	if (n==2)
	{
		cout << a[0] << ' ' << a[1] << endl << a[2] << ' ' << a[3] << endl;
		return 0;		
	}
	
	rep(i,1<<(n*n))
	{
		int cur=0;
		vector <int> bit;
		rep(j,n*n)
			if (i>>j&1) cur+=a[j], bit.pb(j);
		if (cur==per && sz(bit)==n) 
		{
			mask.pb(i);
			rep(j,sz(bit))
			{
				app[bit[j]]++;
				fr(jj,j+1,sz(bit)-1)
					canPair[bit[j]][bit[jj]]=canPair[bit[jj]][bit[j]]=1;
			}
		}
	}
	
	fr(c1,0,n*n-4)
		if (app[c1]>=3)
			fr(c2,c1+1,n*n-1)
				if (canPair[c1][c2] && app[c2]>=3)
					fr(c3,c1+1,n*n-1)
						if (canPair[c1][c3] && canPair[c2][c3] && app[c3]>=3)
							fr(c4,c3+1,n*n-1)
								if (canPair[c1][c4] && canPair[c2][c4] && canPair[c3][c4] && app[c4]>=3)
									go(c1,c2,c3,c4);
}