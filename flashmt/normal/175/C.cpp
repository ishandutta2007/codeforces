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

int n,t;
long long p[111];
pair <long long,long long> a[111],b[111];
long long ans;

int main()
{
	cin >> n;
	rep(i,n) cin >> a[i].se >> a[i].fi;
	
	long long last=0,x;
	cin >> t;
	rep(i,t) 
	{
		cin >> x;
		p[i+1]=x-last;
		last=x;
	}
	p[t+1]=1LL<<60;
	sort(a,a+n);
	int j=1,i=0;
	while (i<n)
	{
		long long active=min(p[j],a[i].se);
		ans+=active*a[i].fi*j;
		p[j]-=active;
		a[i].se-=active;
		if (!p[j]) j++;
		if (!a[i].se) i++;
	}
	cout << ans << endl;
}