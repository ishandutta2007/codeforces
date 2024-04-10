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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int N, L, v1, v2, K;

inline bool f(const ld T) {
	ld l = L, t = T; for(int i = 0; i < N; i++) {
		if(l < 0) return true;
		if(t < 0) return false;
		const ld X = max((ld)0, (t*(ld)v1*(ld)v2 - (ld)v2*l)/((ld)v1-(ld)v2));
		if(l < X) return false;
		if(i == N-1) return true;
		const ld tmpt = X/(ld)v2;
		t -= tmpt; l -= tmpt*(ld)v1;
		const ld tmpl = X-(tmpt*(ld)v1);
		const ld tmptmpt = tmpl/((ld)v1+(ld)v2);
		t -= tmptmpt; l -= tmptmpt*(ld)v1;
	}
	return true;
}
inline ld getAns() {
	ld S = 0, E = (ld)L/v1+15, mid; for(int t = 0; t < 900; t++) {
		mid = (S+E)/2;
		if(f(mid)) E = mid;
		else S = mid;
	}
	return S;
}
int main() {
	scanf("%d%d%d%d%d", &N, &L, &v1, &v2, &K);
	N = (N+K-1)/K;
	printf("%.10f\n", getAns());
	return 0;
}