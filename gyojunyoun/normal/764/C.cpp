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
#define MAXN (100005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline void fg(vector<int> G[], const int& A, const int& B) { G[A].pb(B); G[B].pb(A); }

vector<int> G[MAXN];
pii E[MAXN];
int C[MAXN];
int N;

int ud[MAXN], udc[MAXN];
int uf(const int& idx) { return idx == ud[idx] ? idx : (ud[idx] = uf(ud[idx])); }
inline void uf(const int& A, const int& B) { ud[uf(B)] = uf(A); }

int T[MAXN], dep[MAXN];
void dfs(const int& idx, const int& depth) {
	dep[idx] = depth; T[idx] = 1;
	for(const int& v : G[idx]) if(!dep[v]) {
		dfs(v, depth+1); T[idx] += T[v];
	}
}

int chk[MAXN], chkn;
vector<int> VC, VT;
inline void getAns() {
	bool flag = false;
	for(int i = 1; i <= N; i++) if(udc[i]) VC.pb(i);
	for(int i = 1; i <= N; i++) {
		chkn++;
		for(const int& v : G[i]) {
			const int idx = uf(v);
			if(chk[idx] == chkn) continue;
			chk[idx] = chkn; VT.pb(idx);
		}
		if(chk[uf(i)] != chkn) {
			chk[uf(i)] = chkn; VT.pb(i);
		}
		if(sz(VT) == sz(VC)) {
			printf("YES\n%d\n", i);
			flag = true;
			break;
		}
		vector<int>().swap(VT);
	}
	if(!flag) puts("NO");
}
int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) scanf("%d%d", &E[i].first, &E[i].second);
	for(int i = 1; i <= N; i++) scanf("%d", &C[i]);
	for(int i = 1; i < N; i++) fg(G, E[i].first, E[i].second);
	for(int i = 1; i <= N; i++) ud[i] = i;
	for(int i = 1; i < N; i++) {
		const int &A = E[i].first, &B = E[i].second;
		if(C[A] != C[B]) continue;
		uf(A, B);
	}
	for(int i = 1; i <= N; i++) udc[uf(i)]++;
	//dfs(1, 1);
	getAns();
	return 0;
}