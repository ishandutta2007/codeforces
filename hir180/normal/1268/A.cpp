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
const ll mod = 998244353;
int n,k,a[200005];
char s[200005];
bool ok[200005];
int ans[200005];
int main(){
	scanf("%d%d",&n,&k);
	printf("%d\n",n);
	scanf("%s",&s);
	rep(i,n) a[i] = s[i]-'0';
	rep(i,k) ok[i] = 1;
	for(int i=k;i<n;i++){
		if(a[i] != a[i-k]) break;
		ok[i] = 1;
	}
	if(ok[n-1]){
		printf("%s\n",s);
		return 0;
	}
	for(int i=n-1;i>=0;i--){
		if(i && !ok[i-1]) continue;
		for(int j=a[i]+1;j<10;j++){
			if(i >= k && j != a[i-k]) continue;
			for(int x=0;x<i;x++) ans[x%k] = a[x];
			ans[i%k] = j;
			rep(i,n) printf("%d",ans[i%k]);
			puts(""); return 0;
		}
	}
}