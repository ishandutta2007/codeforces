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
int tt;
int n,k;
char s[2005];
char t[2005];
void solve(){
	scanf("%d%d",&n,&k);
	scanf("%s",&s);
	int nxt = 0;
	for(int i=0;i<k-1;i++){
		t[nxt++] = '(';
		t[nxt++] = ')';
	}
	for(int a=0;a<(n-2*k+2)/2;a++) t[nxt++] = '(';
	for(int a=0;a<(n-2*k+2)/2;a++) t[nxt++] = ')';
	vector<P>ans;
	assert(nxt == n);
	for(int i=0;i<n;i++){
		if(s[i] == t[i]) continue;
		for(int j=i+1;j<n;j++){
			if(s[j] == t[i]){
				ans.pb(P(i,j));
				for(int k=i;k<=j;k++){
					if(k >= i+j-k) break;
					swap(s[k],s[i+j-k]);
				}
				break;
			}
		}
		assert(s[i] == t[i]);
	}
	rep(i,n) assert(s[i] == t[i]);
	printf("%d\n",ans.size());
	rep(i,ans.size()) printf("%d %d\n",1+ans[i].fi,1+ans[i].sc);
}
int main(){
	scanf("%d",&tt);
	while(tt--){
		solve();
	}
	return 0;
}