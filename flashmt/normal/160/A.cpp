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

int n;

int main()
{
	int s=0,t=0,a[111];
	cin >> n;
	rep(i,n) cin >> a[i], s+=a[i];
	sort(a,a+n);
	reverse(a,a+n);
	fr(i,0,n-1)
	{
		t+=a[i];
		if (t>s-t) 
		{
			cout << i+1 << endl;
			return 0;
		}
	}
}