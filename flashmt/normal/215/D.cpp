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

int n,m,t,T,c,x;

long long att(int bus,int a)
{
	if (bus<0) return 1LL<<60;
	int rest=m-a*bus;
	return 1LL*bus*c+1LL*(rest>=a)*rest*x-(!rest?c:0);
}

int main()
{
	long long ans=0;
	cin >> n >> m;
	while (n--)
	{
		cin >> t >> T >> x >> c;
		int a=T-t;
		if (a<=0) ans+=1LL*m*x+c;
		else ans+=min(att(0,a),min(att(m/a,a),att(m/a-1,a)))+c;
	}
	cout << ans << endl;
}