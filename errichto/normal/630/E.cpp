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
#define int long long 

void f(int low, int high, int & even, int & odd) {
	int M = 1000LL * 1000 * 1000 * 1000 + 4;
	low  += M;
	high += M;
	even = high / 2 - (low - 1) / 2;
	odd = high - low + 1 - even;
}

#undef int
int main() {
	#define int long long
	int x1, y1, x2, y2;
	scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
	const int K = 1000 * 1000 * 1000;
	assert(-K <= x1 && x1 <= x2 && x2 <= K);
	assert(-K <= y1 && y1 <= y2 && y2 <= K);
	assert((y2 - y1) % 2 == 0);
	assert((x2 - x1) % 2 == 0);
	ll half = (x2 - x1) / 2;
	int h2 = (y2 - y1) / 2;
	printf("%lld\n", half * h2 + (half + 1) * (h2 + 1));
	return 0;
}