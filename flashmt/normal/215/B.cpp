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

int m,n,k,x,b[5555],c[5555],A,B,r1;
double ans;

int main()
{
	cin >> m;
	while (m--) cin >> x, r1=max(r1,x);
	cin >> n;
	rep(i,n) cin >> b[i];
	cin >> k;
	rep(i,k) cin >> c[i];
	cin >> A >> B;
	
	rep(i,n)
		rep(j,k)
			ans=max(ans,1.0*B*b[i]/(1.0*A*c[j]+B*b[i]));
	
	printf("%.12lf\n",sqrt(ans*r1*r1));
}