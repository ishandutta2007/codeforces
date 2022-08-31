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

const ll mod = 1000000007;

int n,m;
string a,b;

int main(){
	cin >> n >> m >> a >> b;
	int pos = -1;
	rep(i,n){
		if(a[i] == '*') pos = i;
	}
	
	if(pos == -1){
		cout << (a==b?"YES":"NO") << endl;
	}
	else{
		if(n-1 > m){
			puts("NO"); return 0;
		}
		for(int i=0;i<pos;i++){
			if(i < m && a[i] == b[i]);
			else{
				puts("NO"); return 0;
			}
		}
		for(int i=n-1;i>pos;i--){
			int j = i+m-n;
			if(j >= 0 && a[i] == b[j]);
			else{
				puts("NO"); return 0;
			}
		}
		puts("YES");
	}
}