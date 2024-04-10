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
int num[1000005];
const ll mod = 1000000007;
ll cur_len;
int n,x;

void solve(){
	scanf("%d",&x);
	char s[505]; scanf("%s",&s);
	n = strlen(s);
	repn(i,n) num[i] = s[i-1]-'0';
	cur_len = n;
	int pt = 1;
	int nxt = n+1;
	while(pt <= x){
		if(nxt <= x){
		    int curr = nxt-1;
			rep(a,num[pt]-1){
				for(int b=pt+1;b<=curr;b++){
					num[nxt++] = num[b];
					if(nxt == x+1) goto nxt;
				}
			}
		}
		nxt:;
		cur_len += (cur_len-pt) * (num[pt++]-1);
		cur_len %= mod;
	}
	cur_len = (cur_len%mod+mod)%mod;
	printf("%lld\n",cur_len);
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		solve();
	}
}