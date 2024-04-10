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
const int z = 1000000007;

int m,k;
long long n;

struct matrix
{
	long long a[52][52];
	
	matrix () 
	{
		reset(a,0);
	}
	
	matrix operator * (matrix u)
	{
		matrix res;
		rep(i,m)
			rep(j,m)
				rep(k,m)
					res.a[i][j]+=a[i][k]*u.a[k][j], res.a[i][j]%=z;
		return res;
	}
} mat[60];

int get(char s)
{
	if (s<='Z') return s-'A'+26;
	return s-'a';
}

int main()
{
	cin >> n >> m >> k;
	
	rep(i,m) rep(j,m) mat[0].a[i][j]=1;
	
	while (k--)
	{
		string s;
		cin >> s;
		int x=get(s[0]),y=get(s[1]);
		mat[0].a[x][y]=0;
	}
	
	fr(i,1,49) mat[i]=mat[i-1]*mat[i-1];
	
	matrix res;
	rep(i,m) res.a[0][i]=1;
	n--;
	rep(i,50)
		if (n>>i&1) res=res*mat[i];
		
	long long ans=0;
	rep(i,m) ans+=res.a[0][i], ans%=z;
	cout << ans << endl;
}