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
const int z=1000000007;

int n,a[2222],k;
long long c[2222];

long long p(int x,int y)
{
	if (!y) return 1;
	long long res=p(x,y/2);
	res=res*res%z;
	if (y&1) res=res*x%z;
	return res;
}

int main()
{
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	c[0]=1;
	fr(i,1,n-1) c[i]=c[i-1]*(k-1+i)%z*p(i,z-2)%z;
	rep(i,n)
	{
		long long s=0;
		repp(j,i+1) s+=c[i-j]*a[j]%z, s%=z;
		cout << s << ' ';
	}
}