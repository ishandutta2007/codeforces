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
const int nax = 1e6 + 5;

int x[nax], y[nax];

void f(vi w, pii X, pii Y) {
	if(sz(w) <= 2) {
		for(int i : w) printf("%d ", i);
		return;
	}
	if(X.st == X.nd || Y.st == Y.nd) {
		sort(w.begin(), w.end(),
			[](int a, int b) { return x[a] < x[b] || y[a] < y[b]; });
		for(int a : w) printf("%d ", a);
		return;
	}
	int a = X.st + (X.nd - X.st) / 2;
	int b = Y.st + (Y.nd - Y.st) / 2;
	vi k;
	for(int i : w) if(x[i] <= a && y[i] <= b) k.pb(i);
	f(k, mp(X.st, a), mp(Y.st, b));
	k.clear();
	for(int i : w) if(x[i] <= a && y[i] > b) k.pb(i);
	f(k, mp(X.st, a), mp(b+1, Y.nd));
	k.clear();
	
	for(int i : w) if(x[i] > a && y[i] > b) k.pb(i);
	f(k, mp(a+1, X.nd), mp(b+1, Y.nd));
	k.clear();

for(int i : w) if(x[i] > a && y[i] <= b) k.pb(i);
w.clear();
	f(k, mp(a+1, X.nd), mp(Y.st, b));
	k.clear();
}

int main() {
	int n;
	scanf("%d", &n);
	RI(i, n) scanf("%d%d", &x[i], &y[i]);
	vi w;
	RI(i, n) w.pb(i);
	const int LIM = 1000 * 1000;
	f(w, mp(0,LIM), mp(0,LIM));
	return 0;
}