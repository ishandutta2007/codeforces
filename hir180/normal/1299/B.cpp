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
int n;
ll x[100005],y[100005];


int main(){
	cin >> n;
	rep(i,n) cin >> x[i] >> y[i];
	if(n%2 == 1){
		puts("nO"); return 0;
	}
	rep(i,n/2){
		ll X1 = x[(i+1)%n]-x[i];
		ll Y1 = y[(i+1)%n]-y[i];
		ll X2 = x[(i+1+n/2)%n]-x[i+n/2];
		ll Y2 = y[(i+1+n/2)%n]-y[i+n/2];
	//	cout<<X1<<Y1<<X2<<Y2<<endl;
		if(abs(X1) == abs(X2) && abs(Y1) == abs(Y2));
		else {
			puts("nO"); return 0;
		}
	}
	puts("YES");
}