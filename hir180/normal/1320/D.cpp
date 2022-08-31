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
char s[200005];
int a[200005];
int q;

struct hashs{
    #define mod_num 2
    #define SZ 300005
    ll M[10] = {1000000007,1000000009};
    ll c[10] = {37, 41};
    ll val[mod_num][SZ], hs[mod_num][SZ];
     
    void init(vector<int>aa){
    	rep(i,mod_num) val[i][0] = 1;
    	rep(j,SZ-1){
    		rep(i,mod_num) val[i][j+1] = val[i][j] * c[i] % M[i];
    	}
    	rep(j,aa.size()){
    		rep(i,mod_num){
    			hs[i][j+1] = hs[i][j] + val[i][j+1] * (aa[j]+1);
    			hs[i][j+1] %= M[i];
    		}
    	}
    }
    ll get_hs(int l,int r){
    	ll ret[2];
    	rep(i,2){
    		ret[i] = hs[i][r] - hs[i][l-1];
    		ret[i] = ret[i] * val[i][SZ-l];
    		ret[i] = (ret[i]%M[i]+M[i])%M[i];
    	}
    	return ret[0]*M[1]+ret[1];
    }
}h[2];

vector<int>pos;
int main(){
	scanf("%d%s",&n,&s);
	rep(i,n) a[i+1] = s[i]-'0';
	vector<int>ini[2];
	repn(i,n){
		if(a[i] == 0){
			pos.pb(i);
			ini[0].pb(i%2);
			ini[1].pb(1-i%2);
		}
	}
	h[0].init(ini[0]);
	h[1].init(ini[1]);
	scanf("%d",&q);
	rep(i,q){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		int ya = POSU(pos,a+c-1); int xa = POSL(pos,a)+1;
		int yb = POSU(pos,b+c-1); int xb = POSL(pos,b)+1;
		if(ya-xa != yb-xb || h[a%2].get_hs(xa,ya) != h[b%2].get_hs(xb,yb)){
			puts("No");
		}
		else{
			puts("Yes");
		}
	}
}