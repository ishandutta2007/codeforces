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
const int a[] = {3, 15, 81, 6723, 50625, 888888};
const int g[] = {0, 1, 2, 0, 3, 1};

int main()
{
	int n, ans = 0;
	long long x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x < 4) continue;
		long long high = (long long)sqrt(x);
		long long low = (long long)sqrt(high);
		while (low*low*low*low<x) low++;
		int idlow = 0, idhigh = 0;
		while (idlow < 5 && a[idlow] < low) idlow++;
		while (idhigh < 5 && a[idhigh] < high) idhigh++;
		set <int> s;
		fr(i,idlow,idhigh) s.insert(g[i]);
		int G = 0;
		while (s.count(G)) G++;
		ans^=G;
	}
	puts(ans?"Furlo":"Rublo");
}