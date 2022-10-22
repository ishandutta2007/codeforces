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
#define MAXN (1000005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline void fg(vector<int> G[], const int& A, const int& B) { G[A].pb(B); G[B].pb(A); }

vector<int> G[MAXN];
vector<int> SEX;
int ANG[MAXN];
bool chk[MAXN];
ll Ans, SEBINSEX;
int N, M;

void dfs(const int& idx) {
	chk[idx] = true; for(const int& v : G[idx])
		if(!chk[v]) dfs(v);
}
int main() {
	scanf("%d%d", &N, &M);
	if(M < 2) { puts("0"); return 0; }
	for(int i = 0, a, b; i < M; i++) {
		scanf("%d%d", &a, &b);
		if(a == b) { SEX.pb(a); G[a].pb(a); }
		else { fg(G, a, b); ANG[a]++; ANG[b]++; SEBINSEX++; }
	}
	for(int i = 1; i <= N; i++) {
		if(G[i].empty()) continue;
		dfs(i); break;
	}
	for(int i = 1; i <= N; i++) {
		if(G[i].empty()) continue;
		if(chk[i]) continue;
		puts("0"); return 0;
	}
	Ans += (ll)sz(SEX) * (sz(SEX)-1) / 2;
	for(int i = 1; i <= N; i++) {
		Ans += (ll)ANG[i] * (ANG[i]-1) / 2;
		//Ans += (ll)sz(G[i]) * (sz(G[i])-1) / 2;
	}
	Ans += (ll)sz(SEX) * SEBINSEX;
	/*for(const int& v : SEX) {
		//Ans += ANG[v];
		Ans += sz(G[v])-1;
	}*/
	cout << Ans << "\n";
	return 0;
}