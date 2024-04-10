#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second
typedef pair<pair<pii, pii>, int> box;
#define I A.A.A
#define O A.A.B
#define W A.B.A
#define S A.B.B
#define V B

const int MAXN = 600;
const int MAXT = 2 * MAXN;
const int MAXW = 1500;
const int MAXS = 1500;

int N, M;
box B[MAXN];

int dp[MAXN][MAXS];

int main() {
	cin >> N >> M;
	N++;
	B[0].A.A = pii(0, 2 * N);
	B[0].A.B = pii(0, M);
	B[0].B = 0;
	for(int i = 1; i < N; i++) {
		cin >> B[i].I >> B[i].O >> B[i].W >> B[i].S >> B[i].V;
		B[i].S += B[i].W;
		B[i].S = min(B[i].S, M);
	}
	for(int i = 0; i < N; i++) {
		B[i].O *= -1;
	}
	sort(B, B + N);
	for(int i = 0; i < N; i++) {
		B[i].O *= -1;
	}

	for(int i = N - 1; i >= 0; i--) {
		//cerr << B[i].I << ' ' << B[i].O << ' ' << B[i].W << ' ' << B[i].S << ' ' << B[i].V << '\n';
		for(int s = B[i].W; s <= B[i].S; s++) {
			vector<pii> vals;
			vals.push_back(pii(B[i].O, B[i].V));
			for(int j = N - 1; j > i; j--) {
				if(B[j].O > vals[0].A) continue;
				int ma = vals.size();
				int mi = 0;
				while(ma - mi > 1) {
					int md = (mi + ma) / 2;
					if(vals[md].A >= B[j].O) mi = md;
					else ma = md;
				}
				int v = vals[mi].B + dp[j][min(s - B[i].W, B[j].S)];
				assert(vals.back().A >= B[j].I);
				if(vals.back().B >= v) continue;
				while(!vals.empty() && vals.back().A == B[j].I && vals.back().B < v) {
					vals.pop_back();
				}
				assert(!vals.empty());
				vals.push_back(pii(B[j].I, v));
			}
			assert(!vals.empty());
			dp[i][s] = vals.back().B;
			//cerr << i << ' ' << s << ' ' << dp[i][s] << '\n';
		}
	}
	cout << dp[0][M] << '\n';
	return 0;
}