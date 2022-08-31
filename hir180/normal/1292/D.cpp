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
int len[5005];
int lcp[5005];
int cnt[5005];
int rui[5005];
int C[5005][5005];
ll sum,ans;
int n;
int L[100005],R[100005];

int main(){
	scanf("%d",&n); 
	rep(i,n){
		int a; scanf("%d",&a);
		a = max(a,1);
		cnt[a]++;
	}
	repn(i,5000){
		len[i] = len[i-1];
		rep(j,5005) C[i][j] = C[i-1][j];
		int v = i;
		for(int j=2;j*j<=v;j++){
			if(v%j != 0) continue;
			while(v%j == 0){
				C[i][j] ++;
				len[i] ++;
				v /= j;
			}
		}
		if(v != 1){
			C[i][v]++;
			len[i]++;
		}
		rui[i] = rui[i-1]+cnt[i];
	}
	repn(i,4999){
		//i & (i+1)
		for(int j=5000;j>=1;j--){
			if(C[i][j] == C[i+1][j]){
				lcp[i] += C[i][j];
			}
			else{
				lcp[i] += min(C[i][j],C[i+1][j]);
				break;
			}
		}
	}
	repn(i,5000) sum += 1LL*cnt[i]*len[i];
	int alw;
	int k = 0;
	repn(i,5000){
		k += cnt[i];
		if(k > n/2){
			alw = i;
			break;
		}
	}
	int curlen = len[alw];
	for(int i=alw-1;i>=1;i--){
		int nwlen = min(curlen,lcp[i]);
		for(int j=nwlen+1;j<=curlen;j++) L[j] = i+1;
		curlen = nwlen;
	}
	repn(j,curlen) L[j] = 1;
	
	curlen = len[alw];
	for(int i=alw+1;i<=5000;i++){
		int nwlen = min(curlen,lcp[i-1]);
		for(int j=nwlen+1;j<=curlen;j++) R[j] = i-1;
		curlen = nwlen;
	}
	repn(j,curlen) R[j] = 5000;
	
	for(int i=1;i<=100000;i++){
		int x = rui[R[i]] - rui[L[i]-1];
		if(n >= x*2) break;
		sum -= x*2-n;
	}
	
	printf("%lld\n",sum);
}