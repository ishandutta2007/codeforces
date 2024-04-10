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

int n,green,red,period,sx,tree[1000100];
long long a[100100],f[100100];
map <int,int> d;
vector <int> X;

int getUnique(long long u)
{
	return lower_bound(all(X),u%period)-X.begin();
}

void add(int nd,int l,int r,int x,int v)
{
	tree[nd]=v;
	if (l==r) return;
	int m=(l+r)/2;
	if (x<=m) add(nd*2,l,m,x,v);
	else add(nd*2+1,m+1,r,x,v);
}

int get(int nd,int l,int r,int x,int y)
{
	if (l==x && r==y) return tree[nd];
	int m=(l+r)/2,t=0,u=0;
	if (x<=m) t=get(nd*2,l,m,x,min(y,m));
	if (m<y) u=get(nd*2+1,m+1,r,max(x,m+1),y);
	if (t && u) return min(t,u);
	return t+u;
}

int main()
{
	int x;
	cin >> n >> green >> red;
	period=red+green;
	fr(i,1,n+1) scanf("%d",&x), a[i]=a[i-1]+x;
	
	fr(i,0,n) X.pb(a[i]%period);
	sort(all(X));
	X.resize(unique(all(X))-X.begin());
	sx=sz(X);
	
	frr(i,n,1)
	{
		long long from=(a[i]+green)%period, to=(a[i]+period-1)%period;
		int next=0, l=getUnique(from), r=upper_bound(all(X),to)-X.begin();
		r--;
		if (from<=to)
		{
			if (r>=l) next=get(1,0,sx-1,l,r);
		}
		else
		{
			if (l<sx) next=get(1,0,sx-1,l,sx-1);
			int tmp=0;
			if (r>=0) tmp=get(1,0,sx-1,0,r);
			if (tmp && next) next=min(next,tmp);
			else next+=tmp;
		}
		
		if (!next) f[i]=a[n+1]-a[i];
		else
		{
			long long travel=a[next]-a[i];
			f[i]=f[next]+travel+period-travel%period;
		}
		if (i) add(1,0,sx-1,getUnique(a[i]),i);
	}
	
	int q;
	cin >> q;
	while (q--)
	{
		int t,tt;
		scanf("%d",&t);
		tt=t%period;
		
		long long from=(1LL*green-tt+period)%period;
		long long to=(1LL*period-1-tt)%period;
		int next=0, l=getUnique(from), r=upper_bound(all(X),to)-X.begin();
		r--;
		if (from<=to)
		{
			if (r>=l) next=get(1,0,sx-1,l,r);
		}
		else
		{
			if (l<sx) next=get(1,0,sx-1,l,sx-1);
			int tmp=0;
			if (r>=0) tmp=get(1,0,sx-1,0,r);
			if (tmp && next) next=min(next,tmp);
			else next+=tmp;
		}
		
		//cout << t << " = " << next << ' ' << from << ' ' << to << endl;
		if (!next) cout << a[n+1]+t << endl;
		else 
		{
			long long travel=a[next]+t;
			cout << f[next]+travel+period-travel%period << endl;
		}
	}
}