#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

ll gcd(ll a, ll b) {		// 
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll extgcd(ll a, ll b, ll& x, ll& y) {		// 
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}


int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	ll n;
	scanf("%lld", &n);
	REP(i,n) {
		ll p,q,b;
		scanf("%lld", &p);
		scanf("%lld", &q);
		scanf("%lld", &b);
		if(p==0) {
			printf("Finite\n");
			continue;
		}
		ll g=gcd(p,q);
		p/=g;
		q/=g;
		REP(j,20) {
			if(q<=1) break;
			ll g2=gcd(b,q);
			if(g2==1) break;
			while(q%g2==0) q/=g2;
		}
		if(q==1) printf("Finite\n");
		else printf("Infinite\n");
	}
}