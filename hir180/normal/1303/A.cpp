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

int t;
void solve(){
	string s;  cin >> s;
	int mn = INF, mx = -INF, cnt = 0;
	rep(i,s.size()){
		if(s[i] == '1'){
			cnt++;
			mn = min(mn,i);
			mx = max(mx,i);
		}
	}
	if(cnt == 0) puts("0");
	else printf("%d\n",mx-mn+1-cnt);
}
int main(){
	cin>>t;
	while(t--) solve();
}