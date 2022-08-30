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

int col[300005],n,k;
char s[300005];
vector<int>L[300005];

struct uf{
	vector<int>id[300005];
	int cnt[2][300005];
	int par[300005];
	int det[300005];
	void init(){
		rep(i,300005){
			id[i].clear(); id[i].pb(i);
			par[i] = i;
			cnt[0][i] = 1;
			cnt[1][i] = 0;
			det[i] = -1;
		}
	}
	int find(int x){
		if(x == par[x]) return x;
		else return par[x] = find(par[x]);
	}
	int cur_best(int x){
		x = find(x);
		if(det[x] == -1) return min(cnt[0][x],cnt[1][x]);
		else return cnt[det[x]][x];
	}
	int determine(int a,int check){
		int c = col[a];
		a = find(a);
		int pre = -cur_best(a);
		det[a] = check^c;
		pre += cur_best(a);
		return pre;
	}
	int unite(int a,int b,int dif){
		int p = a, q = b;
		int flip = col[p]^col[q]^dif;
		a = find(a); b = find(b);
		if(a == b) return 0;
		int pre = -cur_best(a) - cur_best(b);
		if(id[a].size() < id[b].size()) swap(a,b);
		
		for(auto x:id[b]){
			col[x] ^= flip;
			cnt[col[x]][a]++;
			id[a].pb(x);
		}
		id[b].clear();
		par[b] = a;
		if(det[a] == -1 && det[b] != -1) det[a] = det[b]^flip;
		//cout << det[a] << " " << cnt[0][a] << " " << cnt[1][a] << endl;
		pre += cur_best(a);
		return pre;
	}
}kaede;

int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",&s);
	kaede.init();
	rep(i,k){
		int a; scanf("%d",&a);
		rep(j,a){
			int x; scanf("%d",&x); x--;
			L[x].pb(i);
		}
	}
	int ans = 0;
	rep(i,n){
		if(L[i].empty()){
			ans += 0;
		}
		else if(L[i].size() == 1){
			int x = s[i] == '1';
			ans += kaede.determine(L[i][0],x);
		}
		else{
			assert(L[i].size() == 2);
			int x = s[i] == '0';
			ans += kaede.unite(L[i][0], L[i][1],x);
		}
		printf("%d\n",ans);
	}
}