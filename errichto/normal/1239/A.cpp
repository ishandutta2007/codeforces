#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
using ll = long long;

const int mod = 1e9 + 7;

//~ const int nax = 20;
//~ int grid[nax][nax];

//~ int h, w;

//~ int answer;

//~ const int dx[4] = {-1, 1, 0, 0};
//~ const int dy[4] = {0, 0, -1, 1};

//~ bool inside(int row, int col) {
	//~ return 0 <= row && row < h && 0 <= col && col < w;
//~ }

//~ bool ok(int row, int col) {
	//~ if(!inside(row, col)) {
		//~ return true;
	//~ }
	//~ if(grid[row][col] == 0) {
		//~ return true;
	//~ }
	//~ int cnt = 0;
	//~ for(int dir = 0; dir < 4; ++dir) {
		//~ int r2 = row + dx[dir];
		//~ int c2 = col + dy[dir];
		//~ if(inside(r2, c2) && grid[r2][c2] != 0) {
			//~ if(grid[r2][c2] == grid[row][col]) {
				//~ ++cnt;
			//~ }
		//~ }
	//~ }
	//~ return cnt <= 1;
//~ }

//~ void rec(int row, int col) {
	//~ for(int r : {row - 1, row}) {
		//~ for(int c : {col - 2, col - 1, col}) {
			//~ if(!ok(r, c)) {
				//~ return;
			//~ }
		//~ }
	//~ }
	//~ if(col == w) {
		//~ col = 0;
		//~ row++;
	//~ }
	//~ if(row == h) {
		//~ answer++;
		//~ return;
	//~ }
	//~ grid[row][col] = 1;
	//~ rec(row, col + 1);
	//~ grid[row][col] = 2;
	//~ rec(row, col + 1);
	//~ grid[row][col] = 0;
//~ }

//~ int f(int H, int W) {
	//~ answer = 0;
	//~ h = H;
	//~ w = W;
	//~ rec(0, 0);
	//~ return answer;
//~ }

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int big = max(n, m) + 1;
	vector<int> dp(big + 1);
	//~ dp[0] = 
	dp[1] = 2;
	dp[2] = 4;
	for(int i = 3; i <= big; ++i) {
		// fibo...
		dp[i] = (dp[i-2] + dp[i-1]) % mod;
	}
	printf("%d\n", (dp[n] + dp[m] - 2) % mod); 
	//~ scanf("%d%d", &h, &w);
	//~ if(h < w) {
		//~ swap(h, w);
	//~ }
	//~ for(int h = 1; h <= 8; ++h) {
		//~ for(int w = 1; w <= 8; ++w) {
			//~ printf("%3d ", f(h, w)); // - f(h, w - 1));
		//~ }
		//~ puts("");
	//~ }
	//~ rec(0, 0);
	//~ printf("%d\n", answer);
}