#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000001
#define mod 1000000009
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

int dp[200005],n;
P p[200005];
vector<int>cp;
int seg[(1<<19)];
void update(int pos,int x)
{
	pos += (1<<18)-1;
	seg[pos] = max(seg[pos],x);
	while(pos > 0)
	{
		pos = (pos-1)/2;
		seg[pos] = max(seg[pos*2+1],seg[pos*2+2]);
	}
}
int query(int a,int b,int k,int l,int r)
{
	if(r<a || b<l) return 0;
	if(a<=l && r<=b) return seg[k];
	int lk = query(a,b,k*2+1,l,(l+r)/2);
	int rk = query(a,b,k*2+2,(l+r)/2+1,r);
	return max(lk,rk);
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&p[i].fi,&p[i].sc);
		cp.pb(p[i].fi+p[i].sc);
	}
	sort(p+1,p+n+1);
	sort(cp.begin(),cp.end());
	cp.erase(unique(cp.begin(),cp.end()),cp.end());
	
	for(int i=1;i<=n;i++)
	{
		int f = upper_bound(cp.begin(),cp.end(),p[i].fi-p[i].sc)-cp.begin();
		f--;
		int maxv = 0;
		if(f >= 0) maxv = query(0,f,0,0,(1<<18)-1);
		f = lower_bound(cp.begin(),cp.end(),p[i].fi+p[i].sc)-cp.begin();
		update(f,maxv+1); //cout << f << " " << maxv+1 << endl;
	}
	printf("%d\n",seg[0]);
}