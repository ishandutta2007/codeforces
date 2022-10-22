#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define MAXN (10005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int chk[MAXN<<1], chkn;
int N, K;

int main() {
	for(scanf("%d%d", &N, &K); K--;) {
		vector<int> V; int T; scanf("%d", &T);
		for(int c; T--; scanf("%d", &c), V.pb(c));
		sort(allv(V)); V.erase(unique(allv(V)), V.end());
		chkn++; for(int& v : V) {
			if(v < 0) v = -v + MAXN;
		}
		for(const int& v : V) chk[v] = chkn;
		bool flag = false;
		for(const int& v : V) {
			if(MAXN < v && chk[v-MAXN] == chkn) flag = true;
			if(v < MAXN && chk[v+MAXN] == chkn) flag = true;
		}
		if(!flag) { puts("YES"); return 0; }
	}
	puts("NO");

	return 0;
}