#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <bits/stdc++.h>
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
#define SQ 334
int n,m;
int a[100005],vall[100005],ty[100005],x[100005],y[100005],b[100005];
int pre[100005],nxt[100005];
vector<int>cand[100005];
set<int>S[100005];
vector<int>val[(1<<18)];
vector<ll>bit[(1<<18)][2];
void update(int a){
	int b = a; a += (1<<17)-1;
	val[a] = cand[b];
}
void make(){
	for(int mask=(1<<17)-2;mask>=0;mask--){
		val[mask].resize(val[mask*2+1].size()+val[mask*2+2].size());
		merge(val[mask*2+1].begin(),val[mask*2+1].end(),val[mask*2+2].begin(),val[mask*2+2].end(),val[mask].begin());
		ERASE(val[mask]);
	}
}
int f(int x){
	return x&-x;
}
void add(int a,int V,int T,int add){
	a += (1<<17)-1;
	int e = POSL(val[a],V); e++;
	for(int s=e;s<bit[a][T].size();s+=f(s)) bit[a][T][s]+=add;
	while(a){
		a = (a-1)/2;
		e = POSL(val[a],V); e++;
		for(int s=e;s<bit[a][T].size();s+=f(s)) bit[a][T][s]+=add;
	}
}
ll query(int a,int b,int k,int l,int r,int T,int lim){
	if(r<a||b<l)return 0LL;
	if(a<=l&&r<=b){
		if(T==0){
			int L = POSL(val[k],lim);
			//[0,L)
			ll res=0;
			for(int s=L;s>0;s-=f(s)) res+=bit[k][T][s];
			return res;
		}
		else{
			int L = POSU(val[k],lim);
			//[L,...)
			ll res=0;
			for(int s=bit[k][T].size()-1;s>0;s-=f(s)) res+=bit[k][T][s];
			for(int s=L;s>0;s-=f(s)) res-=bit[k][T][s];
			return res;
		}
	}
	return query(a,b,k*2+1,l,(l+r)/2,T,lim)+query(a,b,k*2+2,(l+r)/2+1,r,T,lim);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); S[a[i]].insert(i); b[i] = a[i];
		pre[i] = vall[a[i]];
		nxt[vall[a[i]]] = i;
		vall[a[i]] = i;
	}
	for(int i=1;i<=n;i++){ S[i].insert(0); S[i].insert(n+1); }
	for(int i=1;i<=n;i++){
		if(nxt[i]==0) nxt[i] = n+1;
		cand[i].pb(pre[i]); cand[i].pb(nxt[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&ty[i],&x[i],&y[i]);
		if(ty[i] == 1){
			if(b[x[i]] == y[i]) continue;
			int k = pre[x[i]],l = nxt[x[i]];
			nxt[k] = l; pre[l] = k; cand[k].pb(nxt[k]); cand[l].pb(pre[l]);
			set<int>::iterator it = S[y[i]].lower_bound(x[i]);
			l=*it; it--; k=*it;
			nxt[k] = x[i]; pre[x[i]] = k; cand[k].pb(nxt[k]); cand[x[i]].pb(pre[x[i]]);
			nxt[x[i]] = l; pre[l] = x[i]; cand[x[i]].pb(nxt[x[i]]); cand[l].pb(pre[l]);
			S[b[x[i]]].erase(S[b[x[i]]].find(x[i]));
			S[y[i]].insert(x[i]);
			b[x[i]] = y[i];
		}
	}
	for(int i=1;i<=n;i++){
		SORT(cand[i]); ERASE(cand[i]); update(i); b[i] = a[i];
	}
	make();
	memset(pre,0,sizeof(pre));memset(nxt,0,sizeof(nxt));memset(vall,0,sizeof(vall)); 
	for(int i=1;i<=n;i++) S[i].clear();
	for(int i=1;i<=n;i++){
		//scanf("%d",&a[i]);
		pre[i] = vall[a[i]]; S[a[i]].insert(i);
		nxt[vall[a[i]]] = i;
		vall[a[i]] = i;
	}
	for(int i=1;i<=n;i++){ S[i].insert(0); S[i].insert(n+1); }
	rep(i,(1<<18)){
		bit[i][0].resize(val[i].size()+1);
		bit[i][1].resize(val[i].size()+1);
	}
	for(int i=1;i<=n;i++){
		if(nxt[i]==0) nxt[i] = n+1;
		add(i,pre[i],0,i); //cout<<pre[i]<<endl;
		add(i,nxt[i],1,i); //cout<<nxt[i]<<endl;
	}
	for(int i=1;i<=m;i++){
		//scanf("%d%d%d",&ty[i],&x[i],&y[i]);
		if(ty[i] == 1){
			if(b[x[i]] == y[i]) continue;
			int k = pre[x[i]],l = nxt[x[i]];
			add(k,nxt[k],1,-k); add(l,pre[l],0,-l);
			nxt[k] = l; pre[l] = k;  //cout<<k<<l<<endl;
			add(k,nxt[k],1,k); add(l,pre[l],0,l);
			set<int>::iterator it = S[y[i]].lower_bound(x[i]);
			l=*it; it--; k=*it;
			add(k,nxt[k],1,-k); add(x[i],pre[x[i]],0,-x[i]);
			nxt[k] = x[i]; pre[x[i]] = k;//cout<<k<<x[i]<<endl;
			add(k,nxt[k],1,k); add(x[i],pre[x[i]],0,x[i]);
			add(x[i],nxt[x[i]],1,-x[i]); add(l,pre[l],0,-l);
			nxt[x[i]] = l; pre[l] = x[i]; //cout<<x[i]<<l<<endl;
			add(x[i],nxt[x[i]],1,x[i]); add(l,pre[l],0,l);
			S[b[x[i]]].erase(S[b[x[i]]].find(x[i]));
			S[y[i]].insert(x[i]);
			b[x[i]] = y[i];
		}
		else{
			ll L = query(x[i],y[i],0,0,(1<<17)-1,0,x[i]);
			ll R = query(x[i],y[i],0,0,(1<<17)-1,1,y[i]);
			printf("%lld\n",R-L);
		}
	}
}