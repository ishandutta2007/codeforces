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

int n,k;
pair <int,int> a[100100];
long long budget;

int main()
{
	cin >> n >> k >> budget;
	fr(i,1,n-1) cin >> a[i].fi, a[i].fi*=-1, a[i].se=i;
	
	sort(a+1,a+n);
	int ans=n;
	long long money=0;
	fr(i,1,k) money-=a[i].fi, ans=min(ans,a[i].se);
	
	if (money<=budget) cout << n << endl;
	else
	{
		fr(i,1,n-1)
			if (money+a[k].fi-a[i].fi>budget) ans=min(ans,a[i].se);
		cout << ans << endl;
	}
}