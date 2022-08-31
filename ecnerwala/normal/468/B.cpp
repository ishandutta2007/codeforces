#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N, S[2];
int P[MAXN]; // starting thing
int V[MAXN];
int R[MAXN]; // whether or not in B

bool has(int v) {
	return v >= 0 && binary_search(V, V + N, v);
}

int ind(int v) {
	return lower_bound(V, V + N, v) - V;
}

bool go() {
	memset(R, -1, sizeof(R));
	for(int i = 0; i < N; i++) {
		if(R[i] != -1) continue;
		int v = V[i];
		int a = S[0] - v, b = S[1] - v;
		bool ha = has(a), hb = has(b);
		if(!ha && !hb) return false;
		if(ha && hb) continue;
		int s = hb;
		for(int cur = v; true; ) {
			if(!has(S[s] - cur)) return false;
			R[ind(cur)] = s;
			R[ind(S[s] - cur)] = s;
			if(S[s] - cur == cur) break;
			int nxt = (S[!s] - (S[s] - cur));
			if(!has(nxt)) break;
			cur = nxt;
		}
	}

	if(S[0] % 2 == 0 && S[1] % 2 == 0) {
		if(has(S[0] / 2) && R[ind(S[0] / 2)] == -1) {
			assert(has(S[1] / 2) && R[ind(S[1] / 2)] == -1);
			int s = 1;
			for(int cur = S[0] / 2; true; ) {
				if(!has(S[s] - cur)) return false;
				R[ind(cur)] = s;
				R[ind(S[s] - cur)] = s;
				if(S[s] - cur == cur) break;
				int nxt = (S[!s] - (S[s] - cur));
				if(!has(nxt)) break;
				cur = nxt;
			}
		}
	}

	for(int i = 0; i < N; i++) {
		if(R[i] != -1) continue;
		// everything else is just a cycle
		int v = V[i];
		int s = 0;
		for(int cur = v; true; ) {
			if(!has(S[s] - cur)) return false;
			R[ind(cur)] = s;
			R[ind(S[s] - cur)] = s;
			int nxt = (S[!s] - (S[s] - cur));
			assert(has(nxt));
			if(nxt == v) break;
			cur = nxt;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> S[0] >> S[1];
	for(int i = 0; i < N; i++) cin >> P[i], V[i] = P[i];
	sort(V, V + N);

	bool good = go();

	if(good) {
		cout << "YES\n";
		for(int i = 0; i < N; i++) {
			cout << R[lower_bound(V, V + N, P[i]) - V] << '\n';
		}
	} else {
		cout << "NO\n";
	}
	return 0;
}