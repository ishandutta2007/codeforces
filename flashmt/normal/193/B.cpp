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

int n,u,r;
long long b[33],k[33],p[33],ans=-(1LL<<60);
vector <long long> a;

long long score(vector <long long> a)
{
	long long res=0;
	fr(i,1,n) res+=a[i]*k[i];
	return res;
}

void att(vector <long long> a,int z,int xored)
{
	if ((u-z)%2==0)ans=max(ans,score(a));
	if (z==u) return;
	vector <long long> A=a;
	fr(i,1,n) A[i]=a[p[i]]+r;
	att(A,z+1,0);
	if (!xored)
	{
		fr(i,1,n) A[i]=a[i]^b[i];
		att(A,z+1,1);
	}
}

int main()
{
	int x;
	a.pb(0);
	cin >> n >> u >> r;
	fr(i,1,n) cin >> x, a.pb(x);
	fr(i,1,n) cin >> b[i];
	fr(i,1,n) cin >> k[i];
	fr(i,1,n) cin >> p[i];
	att(a,0,0);
	cout << ans << endl;
}