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
#define oo 1000111222
#define base 1000000007
using namespace std;

int n,k,L,d[1024];
long long f[1024][1024],factorial[100100],ans;
map <int,int> isLucky;

void gen(int x)
{
	isLucky[x]=++L;
	if (x<100000000) gen(x*10+4), gen(x*10+7);
}

long long power(long long x,int y)
{
	if (!y) return 1;
	long long res=power(x,y/2);
	res=(res*res)%base;
	if (y&1) res=(res*x)%base;
	return res;
}

long long c(int k,int n)
{
	long long res=factorial[n];
	res*=power(factorial[k],base-2); 
	res%=base;
	res*=power(factorial[n-k],base-2);
	res%=base;
	return res;
}

int main()
{
	gen(4); gen(7);
	cin >> n >> k;
	rep(i,n) 
	{
		int x;
		scanf("%d",&x);
		if (isLucky.count(x)) d[isLucky[x]]++;
		else d[0]++;
	}
	
	f[0][0]=1;
	fr(i,1,L)
	{
		f[i][0]=1;
		fr(j,1,i)
			f[i][j]=(f[i-1][j]+f[i-1][j-1]*d[i])%base;
	}
	
	factorial[0]=1;
	fr(i,1,d[0]) factorial[i]=factorial[i-1]*i%base;

	fr(j,0,L)
		if (j<=k && d[0]+j>=k)
		{
			ans+=f[L][j]*c(k-j,d[0]);
			ans%=base;
		}

	cout << ans << endl;
}