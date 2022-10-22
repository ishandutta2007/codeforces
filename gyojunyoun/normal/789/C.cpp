#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define MAXN (100005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline ll myabs(const ll& n) { return n < 0 ? -n : n; }

ll A[MAXN], B[MAXN], S[MAXN];
ll Ans;
int N;

inline ll sex() {
	S[0] = 0; for(int i = 1; i < N; i++) S[i] = S[i-1] + B[i];
	ll ret = 0, mn = 0;
	for(int i = 1; i < N; i++) {
		ret = max(ret, S[i] - mn);
		mn = min(mn, S[i]);
	}
	return ret;
}
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int i = 1; i < N; i++) B[i] = myabs(A[i+1]-A[i]);
	for(int i = 2; i < N; i += 2) B[i] *= (-1);
	Ans = max(Ans, sex());
	for(int i = 1; i < N; i++) B[i] *= (-1);
	Ans = max(Ans, sex());
	cout << Ans << "\n";
	return 0;
}