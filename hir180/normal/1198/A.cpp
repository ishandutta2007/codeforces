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

int n;
ll B,a[400005];

int main(){
	scanf("%d%lld",&n,&B);
	rep(i,n) scanf("%lld",&a[i]);
	sort(a,a+n);
	
	//(B*8)/n
	ll use = (B*8)/n;
	if(use >= 20 || (1<<use) >= n){
		puts("0");
		return 0;
	}
	int ans = INF;
	
	int nxt = 0;
	map<int,int>M;
	int cnt = 0;
	rep(i,n){
		//i(1<<use)
		while(nxt < n){
			if(M[a[nxt]] == 0){
				if(cnt == (1<<use)) break;
				M[a[nxt]]++;
				cnt++;
			}
			else{
				M[a[nxt]]++;
			}
			nxt++;
		}
		//[i,nxt)
		ans = min(ans,n-(nxt-i));
		M[a[i]] --;
		if(M[a[i]] == 0) cnt--;
	}
	cout << ans << endl;
}