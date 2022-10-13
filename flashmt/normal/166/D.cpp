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
#define piii pair<pair<int,int>,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int n,m,tr[200100][10];
long long f[200100][10];
piii customer[200100],tmp[200200];
vector < pair<int,int> > r;
pair <int,int> shoe[100100];
map <int,int> id;

bool cmpp(pair<int,int> i,pair<int,int> j)
{
	return i.fi<j.fi || (i.fi==j.fi && i.se>j.se);
}

bool cmp(pair<pair<int,int>,int> i,pair<pair<int,int>,int> j)
{
	return i.fi.fi<j.fi.fi || (i.fi.fi==j.fi.fi && i.fi.se>j.fi.se);
}

int filter(piii a[],int n)
{
	int m=1;
	tmp[1]=a[1]; 
	fr(i,2,n)
		if (a[i].fi.fi>tmp[m-1].fi.fi) 
		{
			if (a[i].fi.fi>tmp[m].fi.fi && tmp[m].fi.fi>tmp[m-1].fi.fi) 
				tmp[m+1]=mp(mp(tmp[m].fi.fi,0),0), m++;
			tmp[++m]=a[i];
		}
	if (tmp[m].fi.fi>tmp[m-1].fi.fi) tmp[m+1]=mp(mp(tmp[m].fi.fi,0),0), m++;
	fr(i,1,m) a[i]=tmp[i];
	return m;
}

void trace(int i,int j)
{
	if (!i) return;
	int s1=j%3, s2=j/3;
	if (s1) r.pb(mp(customer[i-1].se,id[customer[i-1].fi.fi+s1-1]));
	if (s2) r.pb(mp(customer[i].se,id[customer[i].fi.fi+s2-1]));
	trace(i-2,tr[i][j]);
}

int main()
{
	//freopen("d.in","r",stdin);
	cin >> n;
	fr(i,1,n) cin >> shoe[i].se >> shoe[i].fi, id[shoe[i].fi]=i;
	cin >> m;
	fr(i,1,m) cin >> customer[i].fi.se >> customer[i].fi.fi, customer[i].se=i;
	
	sort(customer+1,customer+m+1,cmp);
	m=filter(customer,m);
	sort(shoe+1,shoe+n+1,cmpp);
	
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for (int i=2,j=1;i<=m;i+=2)
	{
		int len=customer[i-1].fi.fi,money1=customer[i-1].fi.se;
		int money2=customer[i].fi.se;
		vector < pair<int,int> > canFit;
		
		while (j<=n && shoe[j].fi<len) j++;
		int jj=j;
		while (jj<=n && shoe[jj].fi<=len+1) canFit.pb(shoe[jj++]);
		
		if (sz(canFit)==1 && canFit[0].fi>len) 
		{
			canFit.pb(mp(len,oo));
			swap(canFit[0],canFit[1]);
		}
		
		rep(u,9)
			if (f[i-2][u]>=0)
			{
				int used=i>2 && customer[i-2].fi.fi+1==len && (u%3==2 || u/3==2);
				rep(v,9)
				{
					int s1=v%3,s2=v/3,profit=0;
					if (s1>sz(canFit) || s2>sz(canFit) || (s2==s1 && s2)) continue;
					if (used && (s1==1 || s2==1)) continue;
					
					if (s1)
					{
						if (money1<canFit[s1-1].se) continue;
						profit+=canFit[s1-1].se;
					}
					
					if (s2)
					{
						if (money2<canFit[s2-1].se) continue;
						profit+=canFit[s2-1].se;
					}
					
					if (f[i-2][u]+profit>f[i][v])
					{
						f[i][v]=f[i-2][u]+profit;
						tr[i][v]=u;
					}
				}				
			}
	}
	
	long long ans=-1;
	int j=0;
	rep(i,9)
		if (f[m][i]>ans) ans=f[m][i], j=i;
		
	cout << ans << endl;
	trace(m,j);
	cout << sz(r) << endl;
	rep(i,sz(r)) cout << r[i].fi << ' ' << r[i].se << endl;
}