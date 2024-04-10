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
int n,b[105];
vector<int>up,dw;
map<vector<int>,int>M;
int main(){
	cin >> n;
	rep(i,n){
		int a; cin >> a; b[i] = a;
		up.pb(a / (1<<15));
		dw.pb(a % (1<<15));
	}
	rep(i,(1<<15)){
		vector<int>vi;
		rep(j,up.size()){
			int a = (i ^ up[j]);
			vi.pb(__builtin_popcount(a));
		}
		vector<int>vi2;
		for(int j=1;j<up.size();j++) vi2.pb(vi[j]-vi[0]);
		M[vi2] = i;
	}
	rep(i,(1<<15)){
		vector<int>vi;
		rep(j,dw.size()){
			int a = (i ^ dw[j]);
			vi.pb(__builtin_popcount(a));
		}
		vector<int>vi2;
		for(int j=1;j<up.size();j++) vi2.pb(vi[0]-vi[j]);
		if(M.find(vi2) != M.end()){
		    int ans = (M[vi2] << 15) + i;
		    for(int i=1;i<n;i++) assert(__builtin_popcount(b[0]^ans) == __builtin_popcount(b[i]^ans));
			cout << (M[vi2] << 15) + i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}