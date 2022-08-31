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

char p[200005],t[200005];
int n,m,a[200005];
bool ex[200005];
int main(){
	scanf("%s%s",&p,&t);
	n = strlen(p); m = strlen(t);
	repn(i,n) scanf("%d",&a[i]);
	int lb = 0,ub = n;
	while(ub-lb > 1){
		int mid = (lb+ub)/2;
		memset(ex,0,sizeof(ex));
		repn(i,mid) ex[a[i]-1] = 1;
		int nxt = 0;
		rep(i,n){
			if(ex[i]) continue;
			if(p[i] == t[nxt]){
				nxt++;
				if(nxt == m) break;
			}
		}
		if(nxt == m) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
}