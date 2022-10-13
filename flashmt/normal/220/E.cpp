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
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000111222
#define maxN 1
using namespace std;

int n,a[100100],f[100100],mx,g[100100];
long long k;
vector <int> X;

void add(int f[],int x,int v)
{
	while (x<=mx) f[x]+=v, x+=x&-x;
}

int get(int f[],int x)
{
	int res=0;
	while (x) res+=f[x], x-=x&-x;
	return res;
}

int main()
{
	//freopen("c.in","r",stdin);
	cin >> n >> k;
	rep(i,n) cin >> a[i], X.pb(a[i]);
	sort(all(X));
	X.resize(unique(all(X))-X.begin());
	mx=sz(X);
	
	long long total=0,ans=0;
	repp(i,n) 
	{
		a[i]=lower_bound(all(X),a[i])-X.begin();
		total+=get(g,a[i]);
		a[i]++;
		add(g,a[i],1);
	}
	//cout << total << endl;
	//rep(i,n) cout << a[i] << ' '; puts("");
	
	int r=0;
	rep(l,n-1)
	{
		if (r==l) 
		{
			total-=(l-get(f,a[r]));
			add(g,a[r],-1);
			total-=get(g,a[r]-1);
			r++;
		}
		//cout << "rem " << total << endl;
		total+=get(g,a[l]-1)-get(f,a[l])+l;
		add(f,a[l],1);
		//cout << "add " << total << endl;
		while (total>k && r<n)
		{
			total-=(l+1-get(f,a[r]));
			total-=get(g,a[r]-1);
			add(g,a[r],-1);
			r++;
		}
		if (r==n) break;
		//cout << l << ' ' << r << ' ' << total << endl;
		ans+=n-r;
	}
	cout << ans << endl;
}