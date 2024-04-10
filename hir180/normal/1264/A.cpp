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
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int t,n,a[400005],cnt[400005];
void solve(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	int cur = a[0];
	int C = 1;
	int nxt = 0;
	for(int i=1;i<n;i++){
		if(cur == a[i]) C++;
		else{
			cnt[nxt++] = C;
			cur = a[i]; C = 1;
		}
	}
	cnt[nxt++] = C;
	for(int i=1;i<nxt;i++) cnt[i] += cnt[i-1];
	
	int G = cnt[0];
	if(G > n/2){
		puts("0 0 0");
		return;
	}
	int k = upper_bound(cnt,cnt+nxt,n/2)-cnt;
	k--;
	if(k <= 0){
		puts("0 0 0");
		return;
	}
	int l = upper_bound(cnt,cnt+nxt,G+G)-cnt;
	if(l >= k){
		puts("0 0 0");
		return;
	}
	int S = cnt[l]-G;
	int B = cnt[k]-cnt[l];
	if(G < B){
		printf("%d %d %d\n",G,S,B);
	}
	else{
		puts("0 0 0");
	}
	return;
}
int main(){
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}