#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <assert.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fi first
#define sc second
typedef pair<int,int> P;
typedef pair<P,P> P2;
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
vector<int>x[300005],y[300005];
int n;
struct seg{
	int seg[(1<<20)];
	int k;
	void init(int n){
		for(int i=0;;i++){
			if((1<<i) >= n+5){
				rep(j,2<<i) seg[j] = INF;
				k = i; return;
			}
		}
	}
	void update(int a,int x){
		a += (1<<k)-1;
		seg[a] = min(seg[a],x);
		while(a){
			a = (a-1)/2; seg[a] = min(seg[a*2+1],seg[a*2+2]);
		}
		return ;
	}
	int query(int a,int b,int x,int l,int r){
		if(r<a || b<l)return INF;
		if(a<=l&&r<=b) return seg[x];
		return min(query(a,b,x*2+1,l,(l+r)/2),query(a,b,x*2+2,(l+r)/2+1,r));
	}
	int query(int a,int b){ return query(a,b,0,0,(1<<k)-1);}
}kaede[2];
int main(){
	int q; scanf("%d",&q);
	while(q--){
		int n; scanf("%d",&n);
		for(int i=0;i<=n;i++) {x[i].clear();y[i].clear();}
		rep(i,n){int a; scanf("%d",&a); x[a].pb(i);}
		rep(i,n){int a; scanf("%d",&a); y[a].pb(i);}bool bad = 0;
		for(int i=0;i<=n;i++) if(x[i].size() != y[i].size()) bad = 1;
		kaede[0].init(n);
		if(!bad){
			for(int i=n;i>=0;i--){
				for(int j=0;j<x[i].size();j++){
					int a = x[i][j];
					int b = y[i][j];//cout<<a<<" "<<b<<endl;
					int c = kaede[0].query(x[i][j]+1,n);
				
					if(b > c) bad = 1;
				}
				for(int j=0;j<x[i].size();j++) kaede[0].update(x[i][j],y[i][j]);
				//for(int j=0;j<y[i].size();j++) kaede[1].update(y[i][j],1);
			}
		}
		puts(bad?"NO":"YES");
	}
	return 0;
}