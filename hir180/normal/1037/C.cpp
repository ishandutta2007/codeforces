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
#define ld long double
const int mod = 998244353;
char s[2][1000005];
int n,ans;
bool used[1000005];
int main(){
	scanf("%d",&n);
	scanf("%s%s",&s[0],&s[1]);
	rep(i,n) if(s[0][i] != s[1][i]) ans++;
	rep(i,n-1){
		if(used[i] || used[i+1]) continue;
		if(s[0][i] == s[1][i] || s[0][i+1] == s[1][i+1]) continue;
		if(s[0][i] == s[0][i+1]) continue;
		used[i] = used[i+1] = 1;
		ans --;
	}
	printf("%d\n",ans);
}