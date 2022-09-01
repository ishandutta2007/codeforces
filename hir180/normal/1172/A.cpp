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
int n,a[200005],b[200005];
int rui[500005];
int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%d",&a[i]);
		if(a[i] > 0){
			rui[n+1-a[i]+1]++;
		}
	}
	repn(i,n){
		scanf("%d",&b[i]);
		if(b[i] > 0){
			if(i-b[i]+1 >= 0){
				rui[i-b[i]+1]++;
				rui[i-b[i]+2]--;
			}
			rui[i+n+2-b[i]]++;
		}
	}
	for(int i=1;i<=500000;i++){
		rui[i] += rui[i-1];
		if(rui[i] == n){
			cout << i-1 << endl;
			return 0;
		}
	}
}