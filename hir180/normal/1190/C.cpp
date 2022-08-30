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
int n,k;
char f[100005];
vector<int>pos[2];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",&f);
	
	rep(i,n){
		pos[f[i]-'0'].pb(i);
	}
	rep(q,2){
		if(pos[q].empty() || (pos[q].back()-pos[q][0]) < k){
			puts("tokitsukaze");
			return 0;
		}
	}
	bool gote = 1;
	rep(i,n+1-k){
		rep(j,2){
			//[i,i+k-1]j
			//j^1
			int mn = INF, mx = -INF;
			if(pos[j^1][0] < i) mn = pos[j^1][0];
			else{
				int kk = POSU(pos[j^1], i+k-1);
				if(kk < pos[j^1].size()) mn = pos[j^1][kk];
			}
			
			if(pos[j^1].back() > i+k-1) mx = pos[j^1].back();
			else{
				int kk = POSL(pos[j^1], i);
				if(kk) mx = pos[j^1][kk-1];
			}
			//cout<<i<<j<<" "<<mn<<mx<<endl;
			if(mx-mn < k);
			else gote = 0;
		}
	}
	if(gote) puts("quailty");
	else puts("once again");
}