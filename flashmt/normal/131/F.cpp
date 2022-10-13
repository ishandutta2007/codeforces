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
#define maxN 1
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
#define oo 1000111222
using namespace std;
const int dx[]={-1,0,1,0,0};
const int dy[]={0,1,0,-1,0};

int n,m,k,isStar[555][555],row[555][555],s[555];
string a[555];
long long ans;

int main()
{
	cin >> m >> n >> k;
	rep(i,m) cin >> a[i];
	fr(i,1,m-2) fr(j,1,n-2) 
	{
		isStar[i][j]=1;
		rep(z,5) isStar[i][j]&=(a[i-dx[z]][j-dy[z]]=='1');
	}
	m-=2; n-=2;
	fr(i,1,m) fr(j,1,n) row[i][j]=row[i][j-1]+isStar[i][j];
	fr(l,0,n-1) fr(r,l+1,n)
		for (int i=1,j=0;i<=m;i++)
		{
			s[i]=s[i-1]+row[i][r]-row[i][l];
			while (s[i]-s[j]>=k) j++;
			ans+=j;
		}
	cout << ans << endl;
}