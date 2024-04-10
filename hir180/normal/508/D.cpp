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
int n;
vector<int>edge[100005];
int dif[100005];
//directed Eulerian Trail
//u is endpoint
void dfs(int u, vector<int> &trail) {
        while (!edge[u].empty()) {
                int v = edge[u].back();
                edge[u].pop_back();
                dfs(v, trail);
        }
        trail.push_back(u);
}

int ans[200005];
int main(){
	scanf("%d",&n);
	rep(i,n){
		char f[5]; scanf("%s",&f);
		int a[3];
		rep(i,3) a[i] = (int)(f[i]);
		int x = a[0]*300 + a[1];
		int y = a[1]*300 + a[2];
		edge[x].pb(y);
		dif[x]++;
		dif[y]--;
	}
	int s = -1;
	bool bad = 0;
	rep(i,100005){
		if(dif[i] == 0) continue;
		if(abs(dif[i]) >= 2) bad = 1;
		if(dif[i] == 1){
			if(s != -1) bad = 1;
			s = i;
		}
	}
	if(bad){
		puts("NO");
		return 0;
	}
	if(s == -1){
		rep(i,100005){
			if(edge[i].size()){
				 s = i;
				 break;
			}
		}
	}
	vector<int>ret;
	dfs(s,ret);
	if(ret.size() != n+1){
		puts("NO");
		return 0;
	}
	reverse(ret.begin(),ret.end());
	rep(i,ret.size()){
		ans[i] = ret[i]/300;
		ans[i+1] = ret[i]%300;
	}
	puts("YES");
	rep(i,n+2) printf("%c",(char)ans[i]);
	return 0;
}