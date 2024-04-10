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
#define maxN 1
using namespace std;

int n,id[100100],m,tree[100100];
long long k,s[100100];
vector <long long> X;

int get(int x)
{
	int res=0;
	while (x) res+=tree[x], x-=x&-x;
	return res;
}

void add(int x)
{
	while (x<m-1) tree[x]++, x+=x&-x;
}

int ok(long long v)
{
	reset(tree,0);
	add(id[0]);
	long long res=0;
	fr(i,1,n)
	{
		long long most=s[i]-v;
		int curId=lower_bound(X.begin(),X.end(),most)-X.begin();
		if (X[curId]>most) curId--;
		if (curId>0) res+=get(curId);
		add(id[i]);
	}
	return res>=k;
}

int main()
{
	int x;
	long long mx=0,mn=0,oo;
	cin >> n >> k;
	fr(i,1,n) cin >> x, s[i]=s[i-1]+x, X.pb(s[i]), mx=max(mx,s[i]), mn=min(mn,s[i]);
	
	oo=max(mx,-mn)*5+10;
	X.pb(0); X.pb(oo); X.pb(-oo);
	sort(all(X));	
	X.resize(unique(all(X))-X.begin());
	m=X.size();	
	fr(i,0,n) id[i]=lower_bound(all(X),s[i])-X.begin();
	
	long long low=-oo,high=oo,ans;
	while (low<=high)
	{
		long long mid=(low+high)/2;
		if (ok(mid)) ans=mid, low=mid+1;
		else high=mid-1;
	}
	cout << ans << endl;
}