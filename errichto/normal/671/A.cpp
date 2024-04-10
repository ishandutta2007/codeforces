#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

struct P {
	int x, y;
	void read() {
		scanf("%d%d", &x, &y);
	}
};

ld dist(P a, P b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

P t[nax];
ld answer = -1;

void consider(ld x) {
	if(answer < -0.5 || x < answer)
		answer = x;
}

int main() {
	P A, B, T;
	A.read();
	B.read();
	T.read();
	int n;
	scanf("%d", &n);
	ld total = 0;
	REP(i, n) {
		t[i].read();
		total += 2 * dist(T, t[i]);
	}
	REP(_, 2) {
		ld best_save = 0;
		for(int i = 0; i < n; ++i) {
			consider(total - dist(T, t[i]) + dist(A, t[i]));
			consider(total - dist(T, t[i]) + dist(B, t[i]) - best_save);
			maxi(best_save, dist(T, t[i]) - dist(A, t[i]));
		}
		swap(A, B);
	}
	
/*	for(int i = 0; i < n; ++i) {
		t[i].read();
		ld dt = dist(T, t[i]);
		ld maybe_a = dist(A, t[i]);
		ld maybe_b = dist(B, t[i]);
		REP(b,2)REP(c,2)REP(d,2)REP(e,3)
			mini(dp[i+1][1][b][c][d][e], dp[i][0][b][c][d][e] + maybe_a + dt);
		REP(c,2)REP(d,2)REP(e,2)
			mini(dp[i+1][1][1][c][d][e+1], dp[i][0][0][c][d][e] + maybe_a)
			
			mini(dp[i+1][a][1][c][d][e], dp[i][a][0][c][d][e] + dt);
		//total += dist(T, t[i]) * 2;
		//save_a[i] = dist(T, t[i]) - dist(A, t[i]);
		//save_b[i] = dist(T, 
	}
	REP(__, 2) {
		REP(_, 2) {
			// only one will do anything
			ld best_d = 0;
			if(n == 1) best_d = dist(T, t[1]);
			for(int i = 0; i < n; ++i) {
				ld maybe_a = dist(A, t[i]) + dist(t[i], T);
				ld maybe_b = dist(B, t[i]) + dist(t[i], T);
				consider(total - dist(T, t[i]) + maybe_a);
				maxi(best_d, dist(T, t[i]));
			}
			// consider both
			
		}
		reverse(t, t + n);
	}*/
				
			/*ld best_save = 0;
			for(int i = 0; i < n; ++i) {
				//consider(total - dist(T, t[i]) + maybe_a);
				consider(total - dist(T, t[i]) + maybe_b + best_save);
				maxi(best_save, dist(T, t[i]) - maybe_a);
			}
			swap(A, B);*/

	printf("%.10lf\n", (double) answer);
	return 0;
}