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
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
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
int n,m,a,b;
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[2000005],R[2000005];
void make(){
	F[0] = 1;
	for(int i=1;i<2000005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<2000005;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
int main(){
	make();
	cin>>n>>m>>a>>b;
	ll ret = 0;
	for(int i=2;i<=n;i++){
	    if(i-1 > m) continue;
		ll ans = C(m-1,i-2); 
		ans = ans*F[n-2]%mod*R[n-i]%mod;
		if(i != n){
			ans = ans*modpow(n,n-i-1)%mod;
			ans = ans*modpow(m,n-i)%mod;
			ans = ans*1LL*i%mod;
		}
		ret += ans;
	}
	cout<<(ret%mod+mod)%mod<<endl;
}