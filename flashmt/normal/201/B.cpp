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
#define maxN 1
#define sqr(x) ((x)*(x))
using namespace std;

int n,m,a[1010][1010],row[1010],col[1010];

long long d(int i,int j)
{
	return sqr(4LL*i-4*j+2);
}

int main()
{
	cin >> m >> n;
	fr(i,1,m) fr(j,1,n) scanf("%d",a[i]+j), row[i]+=a[i][j], col[j]+=a[i][j];
	
	long long bestX=1LL<<60,bestY=bestX;
	int rx=0,ry=0;
	
	fr(i,0,m)
	{
		long long cur=0;
		fr(j,1,m) cur+=d(i,j)*row[j];
		if (cur<bestX) bestX=cur, rx=i;
	}
	
	fr(i,0,n) 
	{
		long long cur=0;
		fr(j,1,n) cur+=d(i,j)*col[j];
		if (cur<bestY) bestY=cur, ry=i;
	}
	cout << bestX+bestY << endl << rx << ' ' << ry << endl;
}