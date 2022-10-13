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
#define maxN 1
using namespace std;

int n,rank[3030];
pair <int,string> a[3030];

int ok()
{
	if (a[0].first) return 0;
	rank[0]=0;
	fr(i,1,n-1)
	{
		rank[i]=a[i].first;
		if (rank[i]>i) return 0;
		rep(j,i)
			if (rank[j]>=rank[i]) rank[j]++; 
	}
	return 1;
}

int main()
{
	cin >> n;
	rep(i,n) cin >> a[i].second >> a[i].first;
	sort(a,a+n);
	if (!ok()) cout << -1 << endl;
	else
	{
		rep(i,n) cout << a[i].second << ' ' << 10000-rank[i] << endl;
	}
}