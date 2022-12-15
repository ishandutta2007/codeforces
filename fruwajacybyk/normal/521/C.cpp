#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;
#define max_n 100005



lint mod = 1e9+7;

lint fact[max_n];
lint invf[max_n];
lint pows[max_n];
lint pref[max_n];
char s[max_n];

lint powmod(lint a,lint n){
	if(n==0) return 1;
	lint x = powmod(a,n/2);
	if(n%2==0) return (x*1LL*x)%mod;
	else return (((x*1LL*x)%mod)*1LL*a)%mod;
}

lint binom(lint n,lint k){
	if(n<k) return 0;
	return (((fact[n]*1LL*invf[k])%mod) *1LL*invf[n-k])%mod;
}



int main(){
	make2(n,k);
	scanf("%s",s);
	fact[0] = 1;
	FOR(i,1,n+1) fact[i] = (fact[i-1]*1LL*i)%mod;
	invf[0] = 1;
	FOR(i,1,n+1) invf[i] = powmod(fact[i],mod-2);
	pows[0] = 1;
	FOR(i,1,n+1) pows[i] = (pows[i-1]*10LL)%mod;
	if(k==0){
		lint ans = 0;
		FOR(i,0,n){
			ans=(ans*10LL)%mod;
			ans += (s[i]-'0');
			ans %=mod;
		}
		printf("%I64d\n",ans); return 0;
	}
	pref[0] = (binom(n-2,k-1)*1LL*pows[0])%mod;
	FOR(i,1,n){
		pref[i] = pref[i-1];
		lint nowe = (binom(n-2-i,k-1)*1LL*pows[i])%mod;

		pref[i] = (pref[i]+nowe)%mod;
	}
	lint ans = 0;
	FOR(i,0,n){
		lint wklad = ((s[n-1-i]-'0')*1LL*((pref[i]+(binom(n-2-i,k)*1LL*pows[i])%mod)%mod))%mod;
		ans = (ans+wklad)%mod;
	}
	printf("%I64d\n",ans);
}