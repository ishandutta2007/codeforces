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
#define z 1000000007
using namespace std;

long long p(int x,long long y)
{
	if (!y) return 1;
	long long res=p(x,y/2);
	res=res*res%z;
	if (y&1) res=res*x%z;
	return res;
}

int main()
{
	long long n;
	cin >> n;
	long long x=p(2,n);
	cout << x*(x+1)/2%z << endl;
}