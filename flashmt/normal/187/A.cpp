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

int n,pos[200100],a[200100];

int main()
{
	int x,res=1;
	cin >> n;
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> x, pos[x]=i;
	x=pos[a[0]];
	fr(i,1,n-1)
		if (pos[a[i]]<x) break;
		else x=pos[a[i]], res++;
	cout << n-res << endl;
}