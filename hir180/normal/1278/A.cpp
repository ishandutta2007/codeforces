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
	string s,t;
	cin >> s >> t;
	SORT(s);
	rep(i,t.size()){
		if(i+s.size()-1 >= t.size()) break;
		string S = "";
		for(int j=i;j<i+s.size();j++)S.pb(t[j]);
		SORT(S);
		if(s == S) {puts("YES"); return;}
	}
	puts("NO");
}
int main(){
	int t; cin >> t;
	while(t--)solve();
}