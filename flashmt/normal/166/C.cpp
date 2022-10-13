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

int d[100100];

int main()
{
	int n,x,m,low=0,high=0,same=0;
	cin >> n >> m;
	rep(i,n) 
	{
		cin >> x;
		if (x==m) same++;
		else
			if (x<m) low++;
			else high++;
	}
	
	int ans=0;
	if (!same) ans++, same++, n++;
	while (low>=(n+1)/2) ans++, n++;
	while (high>n/2) ans++, n++;
	cout << ans << endl;
}