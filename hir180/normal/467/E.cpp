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
int n,a[500005],pre[500005];
map<int,int>M;
int used[500005];

int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%d",&a[i]);
		if(M.find(a[i]) == M.end()) pre[i] = INF;
		else pre[i] = M[a[i]];
		M[a[i]] = i;
	}
	int beg = 1;
	vector<int>ans;
	while(beg <= n){
		map<int,int>m,cnt;
		vector<int>pos;
		set<int>check;
		for(int i=beg;i<=n;i++){
			cnt[a[i]]++; check.insert(i);
			if(pre[i] != INF && used[pre[i]]){
				ans.pb(used[pre[i]]);
				ans.pb(a[i]);
				ans.pb(used[pre[i]]);
				ans.pb(a[i]);
				beg = i+1; goto nxt;
			}
			else if(cnt[a[i]] == 4){
				rep(ii,4) ans.pb(a[i]);
				beg = i+1; goto nxt;
			}
			else if(m.find(a[i]) == m.end()){
				m[a[i]] = i;
			}
			else{
				int pre = m[a[i]], nxt = i;
				//(pre,nxt)
				auto it = check.upper_bound(pre);
				while(it != check.end() && (*it) < nxt){
					used[*it] = a[i];
					pos.pb(*it);
					it = check.erase(it);
				}
			}
		}
		beg = n+1; nxt:;
		for(auto at:pos) used[at] = 0;
	}
	printf("%d\n",ans.size());
	rep(i,ans.size()){
		printf("%d\n",ans[i]);
	}
	return 0;
}