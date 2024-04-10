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
int n,m,ans[5005];

int main(){
	cin >> n >> m;
	if(n <= 2){
		if(m == 0){
			repn(i,n) cout << i << " ";
			cout<<endl;
		}
		else{
			cout << -1 << endl;
		}
		return 0;
	}
	ans[1] = 1; ans[2] = 2;
	int cur = 0;
	for(int i=3;i<=n;i++){
		if(cur + (i-1)/2 <= m){
			ans[i] = i;
			cur += (i-1)/2;
		}
		else{
			//1...i-1
			for(int x=i+1;;x++){
				int add = 0;
				repn(j,i-1){
					if(j < x-j && x-j <= i-1) add++;
				}
				//cout<<add<<endl;
				if(add == m-cur){
					ans[i] = x;
					for(int j=i+1;j<=n;j++){
						ans[j] = 1000000000 - 100000 * (n-j);
					}
					cur = m;
					goto nxt;
				}
			}
		}
	}
	if(cur != m){
		puts("-1");
		return 0;
	}
	nxt:;
	repn(i,n) printf("%d ",ans[i]);
	puts("");
}