#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long LL;

typedef bitset<2048> bs;
int solveLinear(vector<bs>& A, vi& b, bs& x, int m) {
	int n = sz(A), rank = 0, br;
	assert(m <= sz(x));
	vi col(m); iota(all(col), 0);
	rep(i,0,n) {
		for (br=i; br<n; ++br) if (A[br].any()) break;
		if (br==n) {
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
		rep(j,i+1,n) if(A[j][i]) {
			b[j] ^= b[i];
			A[j] ^= A[i];
		}
		rank++;
	}
	
	x = bs();
	for (int i = rank; i--;) {
		if(!b[i]) continue;
		x[col[i]] = 1;
		rep(j,0,i) b[j] ^= A[j][i];
	}
	return rank;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n, m;
		cin >> n >> m;
		vector<vector<int> > edges(n);
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			a--; b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		int all0 = 1;
		for(int i = 0; i < n; i++){
			if(edges[i].size() % 2 == 1) all0 = 0;
		}
		if(all0){
			cout << 1 << '\n';
			for(int i = 0; i < n; i++){
				cout << 1 << " ";
			}
			cout << '\n';
			continue;
		}
		bs x;
		vector<bs> A(n);
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			if(edges[i].size() % 2 == 0){
				for(int j : edges[i]){
					A[i][j] = 1;
				}
				b[i] = 0;
			} else {
				for(int j : edges[i]){
					A[i][j] = 1;
				}
				A[i][i] = 1;
				b[i] = 1;			
			}
		}
		solveLinear(A, b, x, n);
		cout << 2 << '\n';
		for(int i = 0; i < n; i++){
			cout << (int)x[i] + 1 << " ";
		}
		cout << '\n';
	}
}