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

int n;
int a[200005];
int q;
int las[200005];

struct RMQ{
	#define s (1<<19)
	int seg[s];
	void update(int k,int a){
		k+=s/2-1; seg[k]=a;
		while(k>0){
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return 0;
		if(a<=l && r<=b) return seg[k];
		else{
			int vl=query(a,b,k*2+1,l,(l+r)/2);
			int vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return max(vl,vr);
		}
	}
}kaede;

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	scanf("%d",&q);
	rep(i,q){
		int t; scanf("%d",&t);
		if(t == 1){
			int id, v; scanf("%d%d",&id,&v); id--;
			a[id] = v;
			las[id] = i;
		}
		else{
			int v; scanf("%d",&v);
			kaede.update(i,v);
		}
	}
	
	rep(i,n){
		int ret = max(a[i],kaede.query(las[i],s/2-1,0,0,s/2-1));
		printf("%d\n",ret);
	}
}