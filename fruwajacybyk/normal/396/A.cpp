#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define max_n 200005


using namespace std;



int mod = 1e9+7;

lint powmod(int a,int m){
	if(m==0) return 1;
	lint x = powmod(a,m/2);
	if(m%2) return (((x*x)%mod)*a)%mod;
	else return (x*x)%mod;
}

lint fac[40000];
lint facinv[40000];

lint binom(int m,int k){
	return (((fac[m]*facinv[k])%mod)*facinv[m-k])%mod;
}


int main(){
	int n;
	fac[0]=1;
	FOR(i,1,40000) fac[i] = (fac[i-1]*i)%mod;
	FOR(i,0,40000) facinv[i] = powmod(fac[i],mod-2);

	VI primes; primes.pb(2);
	for(int i=3;i*i<1e9;i+=2){
		bool flaga = true;
		FORE(j,primes){
			if(i%(*j)==0){
				flaga = false;
				break;
			}
		}
		if(flaga) primes.pb(i);
	}
	VI dupa;
	FOR(i,0,primes.size()) dupa.pb(0);
	multiset<int> reszty;
	scanf("%d",&n);
	FOR(i,0,n){
		int u; scanf("%d",&u);
		FOR(j,0,primes.size()){
			while(u%primes[j]==0){
				dupa[j]++;
				u=u/primes[j];
			}
			if(u==1) break;
		}
		if(u!=1) reszty.insert(u);
	}

	lint ans = 1LL;
	FOR(i,0,primes.size()) ans = (ans*binom(dupa[i]+n-1,n-1))%mod;
	int last = 1;
	int ile = 0;
	FORE(i,reszty){
		int x = *i;
		if(x==last) ile++;
		else{
			last = x;
			ans = (ans*binom(ile+n-1,n-1))%mod;
			ile = 1;
		}
	}
	ans = (ans*binom(ile+n-1,n-1))%mod;

	cout<<ans<<endl;

	return 0;
}