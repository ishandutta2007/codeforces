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
pair <int,pair<int,int> > p;

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
	vector <int> used(n*n,0);
	d=e;
	ans[0][0]=a[c1]; ans[n-1][n-1]=a[c2];
	ans[0][n-1]=a[c3]; ans[n-1][0]=a[c4];
	d[a[c1]]--; d[a[c2]]--; d[a[c3]]--; d[a[c4]]--;
	used[c1]=used[c2]=used[c3]=used[c4]=1;
	
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
	
	if (n==4)
	{
		vector <int> rest;
		rep(i,16)
			if (!used[i] && app[i]>=3)
				rest.pb(i);
		int R=sz(rest);
		rep(ib1,R)
			rep(ib2,R)
				if (ib1!=ib2)
				{
					int b1=rest[ib1],b2=rest[ib2];
					if (!canPair[b1][b2]) continue;
					ans[1][1]=a[b1]; ans[1][2]=a[b2];
					d[a[b1]]--; d[a[b2]]--;
					
					int x=per-ans[0][0]-ans[1][1]-ans[3][3]; ans[2][2]=x;
					int y=per-ans[3][0]-ans[1][2]-ans[0][3]; ans[2][1]=y;
					if ((x!=y && d[x]>0 && d[y]>0) || (x==y && d[x]>1))
					{
						
						d[x]--; d[y]--;
						vector <int> rest2;
						for (map <int,int>::iterator it=d.begin();it!=d.end();it++)
							if (it->se>0) rest2.pb(it->fi);
						
						rep(iq1,sz(rest2))
							rep(iq2,sz(rest2))
							{
								int q1=rest2[iq1], q2=rest2[iq2];
								if ((q1==q2 && d[q1]>1) || (q1!=q2 && d[q1]>0 && d[q2]>0))
								{
									d[q1]--; d[q2]--;
									ans[0][1]=q1; ans[1][0]=q2;
									
									int x=per-ans[0][0]-ans[0][1]-ans[0][3]; ans[0][2]=x;
									if (!d[x]) 
									{
										d[q1]++; d[q2]++; continue;
									}
									d[x]--;
									
									int y=per-ans[0][0]-ans[1][0]-ans[3][0]; ans[2][0]=y;
									if (!d[y])
									{
										d[q1]++; d[q2]++; d[x]++; continue;
									}
									d[y]--;
									
									int z=per-ans[0][2]-ans[1][2]-ans[2][2]; ans[3][2]=z;
									if (!d[z])
									{
										d[q1]++; d[q2]++; d[x]++; d[y]++; continue;
									}
									d[z]--;
									
									int t=per-ans[2][0]-ans[2][1]-ans[2][2]; ans[2][3]=t;
									if (!d[t])
									{
										d[q1]++; d[q2]++; d[x]++; d[y]++; d[z]++; continue;
									}
									d[t]--;
									
									int u=per-ans[3][0]-ans[3][2]-ans[3][3]; ans[3][1]=u;
									if (!d[u])
									{
										d[q1]++; d[q2]++; d[x]++; d[y]++; d[z]++; d[t]++; continue;
									}
									d[u]--;
									
									int v=per-ans[0][3]-ans[2][3]-ans[3][3]; ans[1][3]=v;
									if (d[v] && checkDiagonal()) output();
									
									d[q1]++; d[q2]++; d[x]++; d[y]++; d[z]++; d[t]++; d[u]++;
								}
							}
						
						d[x]++; d[y]++;
					}
					
					d[a[b1]]++; d[a[b2]]++;
				}
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
						if (c3!=c2 && canPair[c1][c3] && canPair[c2][c3] && app[c3]>=3)
							fr(c4,c3+1,n*n-1)
								if (c4!=c2 && canPair[c1][c4] && canPair[c2][c4] && canPair[c3][c4] && app[c4]>=3)
									go(c1,c2,c3,c4);
}