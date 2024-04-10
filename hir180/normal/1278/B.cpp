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
void solve(){
	ll a,b; cin >> a >> b;
	a = abs(a-b);
	if(a == 0) { puts("0"); return; }
	for(ll i=1;;i++){
		ll sum = i*(i+1)/2;
		if(a%2 != sum%2) continue;
		if(a > sum) continue;
		cout<<i<<endl;return;
	}
}
int main(){
	int t; cin >> t;
	while(t--)solve();
}