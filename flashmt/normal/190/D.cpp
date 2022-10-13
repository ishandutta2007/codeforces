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

int n,f[400400],k;
pair <int,int> a[400400];

int main()
{
	cin >> n >> k;
	fr(i,1,n) scanf("%d",&a[i].fi), a[i].se=i;
	sort(a+1,a+n+1);
	fr(i,k,n)
		if (a[i-k+1].fi==a[i].fi) f[a[i].se]=a[i-k+1].se;
		
	long long ans=0;
	fr(i,1,n) f[i]=max(f[i],f[i-1]), ans+=f[i];
	cout << ans << endl;
}