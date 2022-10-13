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

int n,len,k,a[100100],N;
long long s[100100],ans;
vector <int> neg;

struct segmentTree
{
	long long sum[500500];
	int cnt[500500];
	
	void update(int nd,int l,int r,int x,int v,int z)
	{
		cnt[nd]+=z; sum[nd]+=v;
		if (l==r) return;
		int m=(l+r)/2;
		if (x<=m) update(nd*2,l,m,x,v,z);
		else update(nd*2+1,m+1,r,x,v,z);
	}
	
	long long get(int nd,int l,int r,int k)
	{
		if (cnt[nd]<=k) return sum[nd];
		if (l==r) return 1LL*neg[l]*k;
		int m=(l+r)/2;
		if (cnt[nd*2+1]>=k) return get(nd*2+1,m+1,r,k);
		return sum[nd*2+1]+get(nd*2,l,m,k-cnt[nd*2+1]);
	}
} tree;

void solve()
{
	neg.clear();
	neg.pb(0);
	fr(i,1,n)
	{
		s[i]=s[i-1]+a[i];
		if (a[i]<0) neg.pb(-a[i]);
	}
	sort(all(neg));
	neg.resize(unique(all(neg))-neg.begin());
	N=sz(neg)-1;
	fr(i,1,n)
	{
		if (a[i]<0)
		{
			int x=lower_bound(all(neg),-a[i])-neg.begin();
			tree.update(1,1,N,x,-a[i],1);
		}
		if (i<len) continue;
		long long best=(N?tree.get(1,1,N,k):0);
		ans=max(ans,s[i]-s[i-len]+best*2);
		if (a[i-len+1]<0)
		{
			int x=lower_bound(all(neg),-a[i-len+1])-neg.begin();
			tree.update(1,1,N,x,a[i-len+1],-1);
		}
	}
}

int main()
{
	cin >> n >> len;
	reset(tree.cnt,0);
	reset(tree.sum,0);
	fr(i,1,n) cin >> a[i];
	cin >> k;
	solve();
	reset(tree.cnt,0);
	reset(tree.sum,0);
	fr(i,1,n) a[i]=-a[i];
	solve();
	cout << ans << endl;
}