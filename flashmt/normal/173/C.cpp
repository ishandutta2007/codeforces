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

int m,n,a[555][555],f[555][555],s[555][555];

int main()
{
	cin >> m >> n;
	fr(i,1,m) 
		fr(j,1,n)
		{
			scanf("%d",&a[i][j]);
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
			f[i][j]=a[i][j];
		}
	
	int ans=-oo;
	for (int k=3;k<=m && k<=n;k+=2)
		fr(i,1,m-k+1)
			fr(j,1,n-k+1)
			{
				f[i][j]=s[i+k-1][j+k-1]+s[i-1][j-1]-s[i+k-1][j-1]-s[i-1][j+k-1]-f[i+1][j+1]-a[i+1][j];
				ans=max(ans,f[i][j]);
			}
	cout << ans << endl;
}