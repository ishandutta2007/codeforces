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
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int sz = 398;
int beg[305];
int ex[305][100005];
int a[100005];
int n;
int lastans = 0;
vector<int>zip[305];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	fill(beg,beg+305,INF);
	for(int i=1;i<=300;i++)
	{
		int s = sz*(i-1)+1;
		if(s > n) continue;
		beg[i] = s;
		for(int j=s;j<=min(sz*i,n);j++)
		{
			ex[i][a[j]]++;
			zip[i].pb(a[j]);
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r,k;
		int t; scanf("%d",&t);
		if(t == 1)
		{
			scanf("%d %d",&l,&r);
			l = (l+lastans-1)%n+1;
			r = (r+lastans-1)%n+1;
			if(l > r) swap(l,r);
			int q = upper_bound(beg+1,beg+300,l)-beg;
			int s = upper_bound(beg+1,beg+300,r)-beg;
			q--; s--;
			//[q,s]
			int x = zip[s][r-beg[s]];
			ex[s][zip[s][r-beg[s]]]--;
			ex[q][zip[s][r-beg[s]]]++;
			vector<int>::iterator it;
			it = zip[s].begin();
			for(int x=0;x<r-beg[s];x++) it++;
			zip[s].erase(it);
			it = zip[q].begin();
			for(int x=0;x<l-beg[q];x++) it++;
			zip[q].insert(it,x);
			for(int i=q+1;i<=s;i++) beg[i]++;
		}
		else
		{
			scanf("%d %d %d",&l,&r,&k);
			l = (l+lastans-1)%n+1;
			r = (r+lastans-1)%n+1;
			k = (k+lastans-1)%n+1;
			if(l > r) swap(l,r);
			int q = upper_bound(beg+1,beg+300,l)-beg;
			int s = upper_bound(beg+1,beg+300,r)-beg;
			q--; s--;
			int res = 0;
			if(q == s)
			{
				for(int i=l-beg[q];i<=r-beg[q];i++) res += (zip[q][i] == k);
			}
			else
			{
				for(int i=l-beg[q];i<zip[q].size();i++) res += (zip[q][i] == k);
				for(int i=q+1;i<=s-1;i++) res += ex[i][k];
				for(int i=0;i<=r-beg[s];i++) res += (zip[s][i] == k);
			}
			printf("%d\n",res); lastans = res;
		}
	}
}