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

int add[1005][2],n,m;
string L,R;
map<string,int>M;
int bit[5005][1005];
P1 calc[5005];
int v[5005];
int main(){
	scanf("%d%d",&n,&m);
	M["?"] = n;
	rep(i,n){
		cin >> L >> R;
		cin >> R;
		M[L] = i;
		if(R[0] == '0' || R[0] == '1'){
			rep(j,m){
				bit[i][j] = R[j]-'0';
			}
			calc[i] = mp(-1,mp(-1,-1));
		}
		else{
			int lb = M[R];
			cin >> R;
			int ty;
			if(R == "AND") ty = 0;
			else if(R == "OR") ty = 1;
			else ty = 2;
			cin >> R;
			int ub = M[R];
			
			calc[i] = mp(ty, mp(lb,ub));
		}
	}
	string ans[2] = {};
	rep(j,m){
		int z = 0, o = 0;
		//0
		memset(v,0,sizeof(v));
		v[n] = 0;
		rep(i,n){
			if(calc[i].fi == -1) {
			    v[i] = bit[i][j];
			    continue;
			}
			if(calc[i].fi == 0) v[i] = v[calc[i].sc.fi] & v[calc[i].sc.sc];
			else if(calc[i].fi == 1) v[i] = v[calc[i].sc.fi] | v[calc[i].sc.sc];
			else v[i] = v[calc[i].sc.fi] ^ v[calc[i].sc.sc];
			
			if(v[i] == 1) z++;
		}
		//1
		memset(v,0,sizeof(v));
		v[n] = 1;
		rep(i,n){
			if(calc[i].fi == -1) {
			    v[i] = bit[i][j];
			    continue;
			}
			if(calc[i].fi == 0) v[i] = v[calc[i].sc.fi] & v[calc[i].sc.sc];
			else if(calc[i].fi == 1) v[i] = v[calc[i].sc.fi] | v[calc[i].sc.sc];
			else v[i] = v[calc[i].sc.fi] ^ v[calc[i].sc.sc];
			
			if(v[i] == 1) o++;
		}
		
		if(z <= o) ans[0].pb('0');
		else ans[0].pb('1');
		
		if(z >= o) ans[1].pb('0');
		else ans[1].pb('1');
	}
	cout<<ans[0]<<endl<<ans[1]<<endl;
}