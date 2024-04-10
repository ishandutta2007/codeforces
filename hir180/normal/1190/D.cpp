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
#define per(i,x) for(int i=x-1;i>=0;i--)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
struct BIT
{
	int bit[200005];
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		i++;
		for(int s=i;s<200005;s+=f(s)) bit[s]+=x;
	}
	int sum(int i)
	{
		i++;
		int res=0;
		for(int s=i;s>0;s-=f(s)) res+=bit[s];
		return res;
	}
}kaede;
int n,x[200005],y[200005];
bool u[200005];
vector<int>zax,zay;
vector<int>query[200005];
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d%d",&x[i],&y[i]);
		zax.pb(x[i]);
		zay.pb(y[i]);
	}
	SORT(zax); SORT(zay);
	ERASE(zax); ERASE(zay);
	rep(i,n){
		y[i] = POSL(zay,y[i]);
		x[i] = POSL(zax,x[i]);
		query[y[i]].pb(x[i]);
	}
	int cur = 0;
	ll ans = 0;
	for(int i=zay.size()-1;i>=0;i--){
		SORT(query[i]);
		rep(j,query[i].size()){
			int t = query[i][j];
			if(u[t] == 0){
				cur++;
				u[t] = 1;
				kaede.add(t,1);
			}
		}
		ans += 1LL*cur*(cur+1)/2;
		rep(j,query[i].size()+1){
			int pre = (j==0?-1:query[i][j-1]);
			int nxt = (j==query[i].size()?zax.size():query[i][j]);
			//(pre,nxt)
			int ex = kaede.sum(nxt-1) - kaede.sum(pre);
			ans -= 1LL * ex * (ex+1)/2;
		}
	}
	printf("%lld\n",ans);
}