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
int n;
vector<ll>val[65],num;
ll a[100005];
int dist[205];
bool used[205];
vector<int>edge[205];
int main(){
	cin >> n;
	rep(i,n) {
		cin >> a[i];
		rep(j,60){
			if(((a[i]>>j)&1LL)){
				val[j].pb(i);
				if(val[j].size() == 3){
					cout << 3 << endl;
					return 0;
				}
			}
		}
		if(a[i]) num.pb(a[i]);
	}
	if(num.size() < 2){
		cout << -1 << endl;
		return 0;
	}
	int ans = INF;
	rep(i,num.size())rep(j,num.size()) if(i<j && (num[i]&num[j]) > 0) {
		fill(dist,dist+205,INF);
		memset(used,0,sizeof(used));
		dist[i] = 0;
		queue<int>que; que.push(i);
		while(!que.empty()){
			int q = que.front(); que.pop();
			if(used[q]) continue; used[q] = 1;
			rep(i,edge[q].size()){
				int to = edge[q][i];
				dist[to] = min(dist[to],dist[q]+1);
				if(!used[to]) que.push(to);
			}
		}
		//cout << i << " " << j << " " << dist[j] << endl;
		ans = min(ans,dist[j]+1);
		edge[i].pb(j);
		edge[j].pb(i);
	}
	cout << (ans>100000?-1:ans) << endl;
}