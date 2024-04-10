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

char sl[nax];
int f(int i) { return sl[i] - '0'; }

int main() {
	scanf("%s", sl);
	int t = f(4) + 10 * (f(3) + 6 * (f(1) + 10 * f(0)));
	int x;
	scanf("%d", &x);
	t = (t + x) % (60 * 24);
	vi w;
	w.pb(t % 10);
	t /= 10;
	w.pb(t % 6);
	t /= 6;
	w.pb(t % 10);
	t /= 10;
	w.pb(t);
	reverse(w.begin(), w.end());
	printf("%d%d:%d%d\n", w[0], w[1], w[2], w[3]);
	return 0;
}