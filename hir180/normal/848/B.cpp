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
int n,w,hh,ty[1000005],a[1000005];
vector<P>v[200005],h[200005];
int go[200005],ans[200005];
int main(){
	cin>>n>>w>>hh;
	rep(i,n){
		int t; scanf("%d%d%d",&ty[i],&a[i],&t);
		if(ty[i] == 1){
			v[100000+t-a[i]].pb(mp(a[i],i));
		}
		else{
			h[100000+t-a[i]].pb(mp(a[i],i));
		}
		go[i] = i;
	}
	for(int i=0;i<=200000;i++) SORT(v[i]),SORT(h[i]);
	for(int i=0;i<=200000;i++){
		if(v[i].empty() || h[i].empty()) continue;
		vector<int>vi;
		for(int j=v[i].size()-1;j>=0;j--) vi.pb(v[i][j].sc);
		rep(j,h[i].size()) vi.pb(h[i][j].sc);
		rep(j,v[i].size()) go[v[i][j].sc] = vi[vi.size()-1-j];
		rep(j,h[i].size()) go[h[i][j].sc] = vi[j];
	}
	for(int i=0;i<n;i++) ans[go[i]] = i;
	for(int i=0;i<n;i++){
		int f = ans[i];
		if(ty[f] == 1){
			printf("%d %d\n",a[f],hh);
		}
		else{
			printf("%d %d\n",w,a[f]);
		}
	}
}