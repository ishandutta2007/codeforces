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
map <long long,long long> g;

long long grundy(long long n)
{
	if (g.count(n)) return g[n];
	long long res=0;
	for (long long i=2;i*i<=n;i++)
		if (n%i==0)
		{
			res=-1;
			if (grundy(i)<0) 
			{
				res=i;
				break;
			}
			if (grundy(n/i)<0) 
			{
				res=n/i;
				break;
			}
		}
	return g[n]=res;
}

int main()
{
	long long n;
	cin >> n;
	long long x=grundy(n);
	if (x<0) puts("2");
	else cout << 1 << endl << x << endl;
}