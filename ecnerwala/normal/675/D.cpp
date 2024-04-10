#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

int N;
int A[MAXN];

unordered_map<int, int> depth;
unordered_map<int, int> par;
set<int> st;

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}

	st.insert(A[0]);
	depth[A[0]] = 0;
	depth[-1] = -1;
	for(int i = 1; i < N; i++) {
		int v = A[i];
		set<int>::iterator it = st.lower_bound(A[i]);
		int p = -1;
		if(it != st.end()) {
			if(depth[*it] > depth[p]) p = *it;
		}
		if(it != st.begin()) {
			it--;
			if(depth[*it] > depth[p]) p = *it;
		}
		assert(p >= 0);
		par[v] = p;
		depth[v] = depth[p] + 1;
		st.insert(v);
	}

	for(int i = 1; i < N; i++) {
		cout << par[A[i]] << ' ';
	}
	cout << '\n';

	return 0;
}