#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[200005],m,k[200005],p[200005];
vector<int>za;
vector<int>pos[200005];
vector<int>query[200005];
struct BIT
{
	int bit[200005];
	void init(){ memset(bit,0,sizeof(bit)); }
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		for(int s=i;s<200005;s+=f(s)) bit[s]+=x;
	}
	int sum(int i)
	{
		int res=0;
		for(int s=i;s>0;s-=f(s)) res+=bit[s];
		return res;
	}
}kaede;
int ans[200005];
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
		za.pb(a[i]);
	}
	SORT(za); ERASE(za);
	rep(i,n){
		a[i] = POSL(za,a[i]);
		pos[a[i]].pb(i);
	}
	scanf("%d",&m);
	rep(i,m){
		scanf("%d%d",&k[i],&p[i]);
		query[k[i]].pb(i);
	}
	kaede.init();
	int id = 0;
	for(int i=za.size()-1;i>=0;i--){
		for(int j=0;j<pos[i].size();j++){
			kaede.add(pos[i][j]+1,1);
			id++;
			for(int k=0;k<query[id].size();k++){
				int y = query[id][k];
				int x = p[y];
				int lb = 0, ub = n;
				while(ub-lb > 1){
					int mid = (lb+ub)/2;
					if(kaede.sum(mid) >= x) ub = mid; else lb = mid;
				}
				ans[y] = za[a[ub-1]];
			}
		}
	}
	rep(i,m) printf("%d\n",ans[i]);
}