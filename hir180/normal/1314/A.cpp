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
vector<P>vec;
priority_queue<int>que;
ll ans,sum;
int main(){
	scanf("%d",&n);
	vec.resize(n,P(0,0));
	rep(i,n){
		scanf("%d",&vec[i].fi);
	}
	rep(i,n){
		scanf("%d",&vec[i].sc);
	}
	SORT(vec);
	int nxt = 0;
	int cur_val;
	while(que.size() || nxt < n){
		if(que.empty()){
			int go = vec[nxt].fi;
			while(nxt < n && vec[nxt].fi == go){
				que.push(vec[nxt].sc);
				sum += vec[nxt].sc;
				nxt++;
			}
			sum -= que.top(); que.pop();
			ans += sum;
			cur_val = go+1;
		}
		else{
			while(nxt < n && vec[nxt].fi == cur_val){
				que.push(vec[nxt].sc);
				sum += vec[nxt].sc;
				nxt++;
			}
			sum -= que.top(); que.pop();
			ans += sum;
			cur_val ++;
		}
	}
	cout << ans << endl;
	return 0;
}