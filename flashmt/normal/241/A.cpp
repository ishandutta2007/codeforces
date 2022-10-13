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
	int n,k,d[1111],s[1111],maxS=0;
	cin >> n >> k;
	fr(i,1,n) cin >> d[i];
	fr(i,1,n) cin >> s[i];

	int ans=0,fuel=0;
	fr(i,1,n)
	{
		ans+=d[i];
		fuel+=s[i];
		maxS=max(maxS,s[i]);
		int need=max(0,(d[i]-fuel+maxS-1)/maxS);
		ans+=k*need;
		fuel+=maxS*need;
		fuel-=d[i];
	}
	
	cout << ans << endl;
}