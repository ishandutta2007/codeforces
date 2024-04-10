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

int n,a[100100],d[100100],b[100100];
long long k;

int main()
{
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	sort(a,a+n);
	int N=1;
	b[0]=a[0];
	d[0]=1;
	fr(i,1,n-1)
	{
		if (a[i]>b[N-1]) b[N++]=a[i];
		d[N-1]++;
	}
	rep(i,N)
		if (1LL*d[i]*n<k) k-=1LL*d[i]*n;
		else 
		{
			cout << b[i] << ' ' << a[(k-1)/d[i]] << endl;
			return 0;
		}
}