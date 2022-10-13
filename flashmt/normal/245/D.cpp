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

int n,b[111][111],bit[111][40],a[111];

int main()
{
	cin >> n;
	rep(i,n) rep(j,n) 
	{
		cin >> b[i][j];
		if (b[i][j]<0) continue;
		rep(k,31)
			if (b[i][j]>>k&1) bit[i][k]=bit[j][k]=1;
	}
	
	rep(i,n) rep(k,31) a[i]|=bit[i][k]<<k;
	
	rep(i,n) rep(j,n)
		if (b[i][j]<0) a[i]=max(a[i],a[j]), a[j]=a[i];
		
	rep(i,n) cout << a[i] << ' ';
}