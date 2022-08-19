#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
using bs = bitset<MAXN*2>;

// https://github.com/kth-competitive-programming/kactl/blob/master/content/numerical/SolveLinearBinary.h
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int solveLinear(vector<bs>& A, vi& b, bs& x, int m) {
	int n = sz(A), rank = 0, br;
	assert(m <= sz(x));
	vi col(m); iota(all(col), 0);
	rep(i,0,n) {
		for (br=i; br<n; ++br) if (A[br].any()) break;
		if (br == n) {
			rep(j,i,n) if(b[j]) return -1;
			break;
		}
		int bc = (int)A[br]._Find_next(i-1);
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) if (A[j][i] != A[j][bc]) {
			A[j].flip(i); A[j].flip(bc);
		}
		rep(j,i+1,n) if (A[j][i]) {
			b[j] ^= b[i];
			A[j] ^= A[i];
		}
		rank++;
	}

	x = bs();
	for (int i = rank; i--;) {
		if (!b[i]) continue;
		x[col[i]] = 1;
		rep(j,0,i) b[j] ^= A[j][i];
	}
	return rank; // (multiple solutions if rank < m)
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N, K; cin >> N >> K;
	vector<pair<uint8_t, uint8_t>> curState(N, {1, 2}); // 1 is red, 2 is yellow, 3 is blue

	vector<bs> A;
	vector<int> b;
	for (int k = 0; k < K; k++) {
		string op; cin >> op;
		int M; cin >> M;
		if (op == "mix") {
			bs lo;
			bs hi;
			for (int z = 0; z < M; z++) {
				int i; cin >> i; i--;
				lo[2*i] = bool(curState[i].first & 1);
				lo[2*i+1] = bool(curState[i].first & 2);
				hi[2*i] = bool(curState[i].second & 1);
				hi[2*i+1] = bool(curState[i].second & 2);
			}
			char c; cin >> c;
			assert(c == 'W' || c == 'R' || c == 'Y' || c == 'B');
			A.push_back(lo); b.push_back(c == 'R' || c == 'B');
			A.push_back(hi); b.push_back(c == 'Y' || c == 'B');
		} else if (op == "RY") {
			for (int z = 0; z < M; z++) {
				int i; cin >> i; i--;
				swap(curState[i].first, curState[i].second);
			}
		} else if (op == "RB") {
			for (int z = 0; z < M; z++) {
				int i; cin >> i; i--;
				curState[i].second ^= curState[i].first;
			}
		} else if (op == "YB") {
			for (int z = 0; z < M; z++) {
				int i; cin >> i; i--;
				curState[i].first ^= curState[i].second;
			}
		} else assert(false);
	}
	
	bs x;
	int rnk = solveLinear(A, b, x, 2*N);

	if (rnk == -1) {
		cout << "NO" << '\n';
		exit(0);
	}

	cout << "YES" << '\n';
	for (int i = 0; i < N; i++) {
		int c = x[2*i+1] * 2 + x[2*i];
		cout << ".RYB"[c];
	}
	cout << '\n';

	return 0;
}