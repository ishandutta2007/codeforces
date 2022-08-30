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

int n,q,a[200005];
bool allzero = 1,mx;

struct seg{
	int seg[(1<<20)];
	void init(){
		fill(seg,seg+(1<<20),INF);
	}
	void update(int a,int x){
		a += (1<<19)-1; seg[a] = x;
		while(a){
			a = (a-1)/2;
			seg[a] = min(seg[a*2+1],seg[a*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(a > b) return INF;
		a += (1<<19)-1;
		b += (1<<19)-1;
		int ret = INF;
		while(a <= b){
		    if((a&1) == 0) { ret = min(ret,seg[a++]); }
		    if((b&1) == 1) { ret = min(ret,seg[b--]); }
		    if(a > b) break;
		    a = (a-1)>>1;
		    b = (b-1)>>1;
		}
		return ret;
	}
}kaede;

vector<int>pos[200005];

int main(){
	scanf("%d%d",&n,&q);
	repn(i,n){
		scanf("%d",&a[i]);
		if(a[i]) allzero = 0;
		if(a[i] == q) mx = 1;
	}
	if(allzero){
		puts("YES");
		repn(i,n) printf("%d ",q);
		puts(""); return 0;
	}
	if(!mx){
	    repn(i,n){
	        if(a[i] == 0){
	            a[i] = q;
	            goto nxt;
	        }
	    }
	    puts("NO"); return 0; nxt:;
	}
	repn(i,n){
		if(a[i] == 0){
			a[i] = a[i-1];
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i] == 0){
			a[i] = a[i+1];
		}
	}
	repn(i,n) assert(a[i]);
	
	kaede.init();
	repn(i,n){
		pos[a[i]].pb(i);
		kaede.update(i,a[i]);
	}
	repn(i,q){
		if(pos[i].empty()) continue;
		int a = pos[i][0], b = pos[i].back();
		int x = kaede.query(a,b,0,0,(1<<19)-1);
		assert(x <= i);
		if(x < i){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	repn(i,n) printf("%d ",a[i]);
	puts("");
}