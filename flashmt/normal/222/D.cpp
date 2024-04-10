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

int n,x,a[100100],b[100100];

int main()
{
	cin >> n >> x;
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	sort(a,a+n); sort(b,b+n);
	reverse(b,b+n);
	int ans=0,i=0,j=0;
	while (i<n && j<n)
	{
		while (i<n && a[i]+b[j]<x) i++;
		ans+=i<n;
		j++; i++;
	}
	cout << 1 << ' ' << ans << endl;
}