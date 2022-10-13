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

int win(long long a,long long b)
{
	if (!a || !b) return 0;
	long long x=win(b%a,a);
	if (!x) return 1;
	b/=a;
	if (a&1) return b%2==0;
	long long z=b%(a+1);
	return z%2==0;
}

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		long long a,b;
		cin >> a >> b;
		if (a>b) swap(a,b);
		puts(win(a,b)?"First":"Second");
	}
}