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

long long p[19];

long long calc(long long n)
{
	if (n<10) return n;
	
	int a[30],l=0;
	long long t=n,res=9;
	
	while (t) a[l++]=t%10, t/=10;
	
	fr(i,2,l-1) res+=p[i-2]*9;
	
	long long u=0;
	frr(i,l-2,1) u=u*10+a[i];
	
	res+=p[l-2]*(a[l-1]-1)+u+1-(a[l-1]>a[0]);
	return res;
}

int main()
{
	rep(i,19) p[i]=(i?p[i-1]*10:1);
	long long l,r;
	cin >> l >> r;
	cout << calc(r)-calc(l-1) << endl;
}