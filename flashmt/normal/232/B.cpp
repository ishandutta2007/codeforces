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
const int z = 1000000007;

long long f[13131],c[111][111],g[111],p[111][111];

long long power(long long x,long long y)
{
	if (!y) return 1;
	long long r=power(x,y/2);
	r=r*r%z;
	if (y%2) r=r*x%z;
	return r;
}

int main()
{
	long long n,m,k;
	cin >> n >> m >> k;
	
	fr(i,1,n) g[i]=m/n+(m%n>=i);
	
	fr(i,0,100)
		fr(j,0,i)
		{
			c[i][j]=(j?(c[i-1][j]+c[i-1][j-1])%z:1);
			p[i][j]=power(c[i][j],m/n);
		}
	
	f[0]=1;
	fr(i,1,n)
		frr(j,i*n,0)
			if (f[j])
				fr(k,1,n)
				{
					if (g[i]==m/n) f[k+j]+=f[j]*p[n][k];
					else f[k+j]+=f[j]*p[n][k]%z*c[n][k];
					f[j+k]%=z;
				}
					
	cout << f[k] << endl;
}