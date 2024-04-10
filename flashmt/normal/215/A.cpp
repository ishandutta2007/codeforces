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

int main()
{
	int m,n,a[55],b[55];
	
	cin >> m;
	rep(i,m) cin >> a[i];
	cin >> n;
	rep(i,n) cin >> b[i];
	
	int best=0,ans=0;
	
	rep(i,m)
		rep(j,n)
			if (b[j]%a[i]==0)
				best=max(best,b[j]/a[i]);
	
	rep(i,m)
		rep(j,n)
			ans+=(a[i]*best==b[j]);
	
	cout << ans << endl;
}