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
char s[200005];
bool u[200005];
int n;
void solve(){
	scanf("%s",&s); n = strlen(s);
	int ans = 0;
	vector<int>pos;
	rep(i,n) u[i] = 0;
	rep(i,n){
		if(i+4 >= n) continue;
		if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e'){
			pos.pb(i+2);
			u[i+2] = 1;
		}
	}
	rep(i,n){
		if(i+2 >= n) continue;
		if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && !u[i+2]) pos.pb(i+1);
		if(s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e' && !u[i]) pos.pb(i+1);
	}
	SORT(pos); ERASE(pos);
	printf("%d\n",pos.size());
	if(pos.empty()) puts("");
	rep(i,pos.size()) printf("%d%c",1+pos[i],(i+1==pos.size()?'\n':' '));
}
int main(){
	int t; scanf("%d",&t);
	while(t--) solve();
}

/*/10
onetwonetwooneooonetwooo
two
one
twooooo
ttttwo
ttwwoo
ooone
onnne
oneeeee
oneeeeeeetwooooo*/