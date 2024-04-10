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

int main()
{
	int n,k,a[100100],m=0,d[100100]={0},x;
	cin >> n >> k;
	rep(i,n) 
	{
		cin >> x;
		if (!m || x!=a[m-1]) a[m++]=x;
	}
	
	int best=-1,ans=-1;

	d[a[0]]++;
	fr(i,1,m-2)
		if (a[i-1]==a[i+1]) d[a[i]]+=2;
		else d[a[i]]++;
	d[a[m-1]]++;	
	
	fr(i,1,k)	
		if (d[i]>best) best=d[i], ans=i;
		
	cout << ans << endl;
}