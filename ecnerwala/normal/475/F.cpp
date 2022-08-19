#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 1e5 + 20;
int N;
pii P[MAXN];

typedef multiset<pair<int, int>> mii;
typedef mii::iterator mit;
typedef pair<mii, mii> bimii;
typedef pair<bimii, bimii> uni;

// split a into a and b
bool split(uni &a, uni &b) {
	mit beg[4] = {a.A.A.begin(), a.A.B.begin(), a.B.A.begin(), a.B.B.begin()};
	mit iters[4] = {a.A.A.begin(), a.A.B.begin(), a.B.A.begin(), a.B.B.begin()};
	unsigned int n = a.A.A.size();
	assert(n == a.A.B.size());
	assert(n == a.B.A.size());
	assert(n == a.B.B.size());
	for(int i = 1; 2 * i <= int(n); i++) {
		for(int k = 0; k < 4; k++) {
			mit cur = iters[k];
			mit nxt = ++iters[k];
			if(abs(nxt->A - cur->A) > 1) {
				// split
				for(mit it = beg[k]; it != iters[k]; ) {
					mit nit = it;
					nit++;

					int i = it->B;

					a.A.A.erase(pii(P[i].A, i));
					a.A.B.erase(pii(-P[i].A, i));
					a.B.A.erase(pii(P[i].B, i));
					a.B.B.erase(pii(-P[i].B, i));

					b.A.A.insert(pii(P[i].A, i));
					b.A.B.insert(pii(-P[i].A, i));
					b.B.A.insert(pii(P[i].B, i));
					b.B.B.insert(pii(-P[i].B, i));

					it = nit;
				}
				return true;
			}
		}
	}
	return false;
}

int dfs(uni &a) {
	uni b;
	if(split(a, b)) {
		return dfs(a) + dfs(b);
	} else {
		return 1;
	}
}

int main() {
	int N; cin >> N;
	uni st;
	for(int i = 0; i < N; i++) {
		cin >> P[i].A >> P[i].B;
		st.A.A.insert(pii(P[i].A, i));
		st.A.B.insert(pii(-P[i].A, i));
		st.B.A.insert(pii(P[i].B, i));
		st.B.B.insert(pii(-P[i].B, i));
	}
	cout << dfs(st) << '\n';
	return 0;
}