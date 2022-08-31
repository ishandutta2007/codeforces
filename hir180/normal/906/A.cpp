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

bool pos[26];
int n;

int main(){
	cin>>n; n--;
	int ans = 0;
	rep(i,26) pos[i] = 1;
	while(n--){
		string x,y; cin >> x >> y;
		int alr = 0;
		rep(i,26) alr += pos[i];
		assert(alr >= 1);
		alr = (alr == 1);
		
		if(x == "!"){
			bool ex[26]={};
			rep(i,y.size()) ex[y[i]-'a'] = 1;
			rep(i,26) if(!ex[i]) pos[i] = 0;
			if(alr) ans++;
		}
		else if(x == "."){
			bool ex[26]={};
			rep(i,y.size()) ex[y[i]-'a'] = 1;
			rep(i,26) if(ex[i]) pos[i] = 0;
		}
		else {
			bool ex[26]={};
			rep(i,y.size()) ex[y[i]-'a'] = 1;
			rep(i,26) if(ex[i]) pos[i] = 0;
			if(alr) ans++;
		}
	}
	cout << ans << endl;
}