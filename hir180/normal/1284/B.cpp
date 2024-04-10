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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const ll mod = 1000000007;
int n;
vector<vector<int>>vec;
vector<int>top;

int main(){
	scanf("%d",&n);
	rep(i,n){
		int a; scanf("%d",&a);
		vector<int>v;
		rep(j,a){
			int aa; scanf("%d",&aa);
			v.pb(aa);
		}
		vec.pb(v);
		rep(j,a-1){
			if(v[j] < v[j+1]){
				goto nxt;
			}
		}
		top.pb(v[0]);
		nxt:;
	}
	SORT(top);
	ll ans = 1LL*n*n;
	
	rep(i,n){
		int a = vec[i].size(),val;
		rep(j,a-1){
			if(vec[i][j] < vec[i][j+1]){
				goto nxt2;
			}
		}
		val = vec[i].back();
		ans -= POSU(top,val);
		nxt2:;
	}
	
	cout << ans << endl;
}