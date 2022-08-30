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
string s;
vector<int>pos[2];
int main(){
	cin>>s;
	int n=s.size();
	rep(i,n){
		pos[s[i]==')'].pb(i);
	}
	for(int x=500;x>=1;x--){
		if(pos[0].size() < x || pos[1].size() < x) continue;
		int a = pos[0][x-1];
		int b = pos[1][pos[1].size()-x];
		if(a < b){
			puts("1");
			printf("%d\n",2*x);
			rep(i,x) printf("%d ",++pos[0][i]);
			for(int i=x;i>=1;i--) printf("%d ",++pos[1][pos[1].size()-i]);
			puts("");
			return 0;
		}
	}
	puts("0");
}