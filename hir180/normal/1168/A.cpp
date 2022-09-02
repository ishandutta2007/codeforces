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
int n,m,a[300005];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d",&a[i]);
	int lb = -1, ub = m-1;
	while(ub-lb > 1){
		int mid = (lb+ub)/2;
		int pre = 0;
		rep(i,n){
			int L = a[i];
			int R = (a[i]+mid)%m;
			if(L<=R){
				if(pre < L) pre = L;
				else if(pre <= R);
				else goto nxt;
			}
			else{
				if(pre <= R);
				else if(pre < L) pre = L;
			}
		}
		ub = mid; continue;
		nxt:; lb = mid;
	}
	cout << ub << endl;
}