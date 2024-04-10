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

long long gcd(long long x,long long y)
{
	return x && y?gcd(y,x%y):x+y;
}

long long lcm(long long x,long long y)
{
	return x/gcd(x,y)*y;
}

int main()
{
	long long ans=0,n;
	cin >> n;
	fr(i,max(n-100,1LL),n)
		fr(j,i,n)
			fr(k,j,n)
				ans=max(ans,lcm(lcm(i,j),k));
	cout << ans << endl;
}