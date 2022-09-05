#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
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
const int nax = 32000;
const int mod = 1e9 + 7;

bool is[nax];
pii p[2 * nax];
vi w;

bool isPrime(int n) {
	for(int i : w) {
		if(i * i > n) return true;
		if(n % i == 0) return false;
	}
	return true;
}

int main() {
	FOR(i,2,nax-1) is[i] = true;
	for(int i = 2; i * i < nax; ++i) if(is[i])
		for(int j = i * i; j < nax; j += i)
			is[j] = false;
	FOR(i,2,nax-1) if(is[i]) w.pb(i);
	for(int i : w) p[i] = mp(i, 0);
	for(int i : w) for(int j : w) p[i+j] = mp(i,j);
	int n;
	scanf("%d", &n);
	int memo = n;
	while(true) {
		while(!isPrime(n)) --n;
		int more = memo - n;
		if(p[more].st + p[more].nd == more) {
			vi res = vi{n};
			if(p[more].st) res.pb(p[more].st);
			if(p[more].nd) res.pb(p[more].nd);
			printf("%d\n", sz(res));
			for(int x : res) printf("%d ", x);
			puts("");
			return 0;
		}
		--n;
	}
	return 0;
}