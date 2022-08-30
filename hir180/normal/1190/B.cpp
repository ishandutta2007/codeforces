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
#define per(i,x) for(int i=x-1;i>=0;i--)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
int n;
map<int,int>M;
ll sum ;
int main(){
	scanf("%d",&n);
	rep(i,n){
		int a; scanf("%d",&a);
		M[a]++; sum+=a;
	}
	if(sum == 0){
		puts("cslnb");
		return 0;
	}
	int cnt = 0;
	for(auto a:M){
		if(a.sc >= 2) cnt++;
	}
	bool ok = 0;
	for(auto a:M){
		if(a.fi == 0) continue;
		int nwcnt = cnt;
		if(a.sc == 2) nwcnt--;
		if(M[a.fi-1] == 1) nwcnt++;
		
		if(nwcnt == 0){
			ok = 1;
		}
	}
	if(!ok){
		puts("cslnb");
		return 0;
	}
	else{
		ll f = sum - 1LL*(n-1)*n/2;
		assert(f >= 0);
		puts(f%2==0?"cslnb":"sjfnb");
	}
}