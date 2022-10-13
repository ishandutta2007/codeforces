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
#define z 1000000007 
using namespace std;

int n,a[11];
long long f[111],c[111][111];

int main()
{
	cin >> n;
	rep(i,10) cin >> a[i];
	rep(i,111)
		fr(j,0,i)
			c[i][j]=(j?(c[i-1][j]+c[i-1][j-1])%z:1);
			
	f[0]=1;
	repp(i,10)
	{
		frr(j,n,(i?0:1))
		{
			fr(k,a[i],n)
				if (j+k<=n && k)
				{
					f[j+k]+=f[j]*(i?c[j+k][k]:c[j+k-1][k]);
					f[j+k]%=z;
				}
			if (a[i]) f[j]=0;
		}
	}
	
	long long ans=0;
	fr(i,1,n) ans+=f[i], ans%=z;
	cout << ans << endl;
}