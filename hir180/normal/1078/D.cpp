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
}L[18],R[18];
int a[300005];
int n;
int le[300005][20],ri[300005][20];
 
int main(){
	int n; scanf("%d",&n);
	if(n == 1){ puts("0"); return 0; }
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n){
		a[i+n] = a[i];
		a[i+n+n] = a[i];
	}
	rep(i,17) {L[i].init(); R[i].init(); }
	rep(i,3*n){
		le[i][0] = max(0,i-a[i]);
		ri[i][0] = min(3*n-1,i+a[i]);
		
		L[0].update(i,le[i][0]);
		R[0].update(i,-ri[i][0]);
	}
	for(int j=0;j<16;j++) for(int i=0;i<3*n;i++){
		int x = le[i][j];
		int y = ri[i][j];
		if(y-x+1 >= n){
		    le[i][j+1] = x; ri[i][j+1] = y;
    		L[j+1].update(i,x);
    		R[j+1].update(i,-y);
		}
		else{
    		int X = L[j].query(x,y,0,0,(1<<19)-1);
    		int Y = -R[j].query(x,y,0,0,(1<<19)-1);
    		le[i][j+1] = X; ri[i][j+1] = Y;
    		L[j+1].update(i,X);
    		R[j+1].update(i,-Y);
		}
	}
	for(int i=n;i<2*n;i++){
		int cx = i, cy = i;
		int ans = 0;
		for(int j=16;j>=0;j--){
			int ccx = L[j].query(cx,cy,0,0,(1<<19)-1);
			int ccy = -R[j].query(cx,cy,0,0,(1<<19)-1);
			if(ccy-ccx+1 >= n){
				continue;
			}
			else{
				cx = ccx; cy = ccy;
				ans |= (1<<j);
			}
		}
		printf("%d\n",1+ans);
	}
	
	return 0;
}