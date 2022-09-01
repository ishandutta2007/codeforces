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
int n,q,a[300005];
int L[300005],R[300005];
int go[300005][20];
vector<int>num[20];
vector<int>nxt[300005];
int main(){
	scanf("%d%d",&n,&q);
	rep(i,300005) rep(j,20) go[i][j] = INF;
	repn(i,n){
		scanf("%d",&a[i]);
		rep(j,19){
			if(((a[i]>>j)&1)){
				if(num[j].size()) nxt[num[j][num[j].size()-1]].pb(i);
				num[j].pb(i);
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<19;j++){
			if(((a[i]>>j)&1)){
				go[i][j] = i;
			}
			else{
				rep(k,nxt[i].size()){
					go[i][j] = min(go[i][j],go[nxt[i][k]][j]);
				}
			}
		}
	}
	rep(i,q){
		scanf("%d%d",&L[i],&R[i]);
		rep(j,19){
			if(go[L[i]][j] <= R[i] && ((a[R[i]]>>j)&1)){
				puts("Shi"); goto nxt;
			}
		}
		puts("Fou");
		nxt:;
	}
}