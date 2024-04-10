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
const int nax = 2e6 + 5;

int t[nax];
int poz[nax];

int main() {
	int n;
	scanf("%d", &n);
	if(n == 1) {
		puts("1 1");
		return 0;
	}
	if(n == 2) {
		puts("1 1 2 2");
		return 0;
	}
	// up to n-1
	vi odd, even;
	RI(i, n - 1) {
		if(i % 2) odd.pb(i);
		else even.pb(i);
	}
	RI(i, sz(odd)) t[i] = odd[sz(odd)-i];
	RI(i, sz(odd)) t[sz(odd)+i] = odd[i-1];
	RI(i, sz(even)) t[2*sz(odd)+i] = even[sz(even)-i];
	RI(i, sz(even)) t[2*sz(odd)+sz(even)+i+1] = even[i-1];
	RI(i, 2 * n) t[i] = n - t[i];
	RI(i, 2 * n) printf("%d ", t[i]);
	puts("");
	/*
	
	int odd = 0;
	RI(i, n - 1) if (i % 2 == 1
	REP(i, 2 * n) t[i] = i / 2 + 1;
	do {
		REP(i, n + 2) poz[i] = 0;
		int s = 0;
		REP(i, 2 * n) {
			int x = t[i];
			if(poz[x] == 0) poz[x] = i;
			else s += (n - x) * abs(i - poz[x] + x - n);
		}
		if(s == 0) {
			printf("%d\n", s);
			REP(i, 2 * n) printf("%d ", t[i]);
			puts("");
			puts("");
		}
	} while(next_permutation(t, t + 2 * n));*/
	return 0;
}