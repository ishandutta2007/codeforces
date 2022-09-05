#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= (b); ++i)
#define FORD(i,a,b) for(int i = a; i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e7 + 5;

bool f(int a) {
	vi w;
	while(a) {
		w.pb(a%10);
		a /= 10;
	}
	int d = sz(w);
	REP(i,d/2) if(w[i] != w[d-1-i]) return false;
	return true;
}

bool is[nax];
bool pali[nax];

int main()
{
	FOR(i,2,nax-1) is[i] = true;
	for(int i = 2; i * i < nax; ++i) if(is[i])
		for(int j = i * i; j < nax; j += i) is[j] = false;
	int PI = 0;
	FOR(i,2,nax-1)if(is[i]) PI++;
	ll p, q;
	scanf("%lld%lld", &p, &q);
	REP(i,10) pali[i] = f(i);
	FOR(i,10,nax-1) {
		int x = i;
		while(x >= 10) x /= 10;
		i += x;
		pali[i] = f(i);
		i += 9 - x;
	}
	int RUB = 0;
	RI(i,nax-1)if(pali[i]) RUB++;
	FORD(i,nax-1,1) {
		if(PI*q <= p * RUB) {
			printf("%d\n", i);
			return 0;
		}
		if(pali[i]) RUB--;
		if(is[i]) PI--;
	}
	
	
	return 0;
}