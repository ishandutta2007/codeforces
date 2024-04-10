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
const ll mod = 998244353;

ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[1000005],R[1000005];
void make(){
	F[0] = 1;
	for(int i=1;i<1000005;i++) F[i] = F[i-1]*i%mod;
	R[1000004] = modpow(F[1000004],mod-2);
	for(int i=1000003;i>=0;i--){
		R[i] = R[i+1]*1LL*(i+1)%mod;
	}
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
char s[1000005];
int n;
ll rui[1000005],rui2[1000005];
int fr,op;
int main(){
	make();
	scanf("%s",&s);
	n = strlen(s);
	rep(i,n) if(s[i] == '?') fr++; else if(s[i] == '(') op++;
	for(int i=0;i<1000005;i++){
		if(i) rui[i] = rui[i-1];
		if(i <= fr) rui[i] = (rui[i]+C(fr,i))%mod;
	}
	if(fr){
		for(int i=0;i<1000005;i++){
			if(i) rui2[i] = rui2[i-1];
			if(i <= fr-1) rui2[i] = (rui2[i]+C(fr-1,i))%mod;
		}
	}
	
	ll ans = 0;
	rep(a,n){
		if(s[a] == ')') continue;
		if(s[a] == '('){
			//( is less than n-1-a-(op-1)
			if(n-2-a-(op-1) >= 0) ans += rui[n-2-a-(op-1)];
		}
		else{
			//( is less than n-1-a-op
			if(n-2-a-op >= 0) ans += rui2[n-2-a-op];
		}
		//cout << ans << endl;
	}
	printf("%lld\n",(ans%mod+mod)%mod);
}