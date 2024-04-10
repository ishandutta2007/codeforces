#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1e9 + 7;
constexpr int maxn = 1200;
constexpr int maxd = 54;
const int K = 10;
struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};
vector<Vertex> t(1);
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - '0';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}
int go(int v, char ch);
int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}
int go(int v, char ch) {
    int c = ch - '0';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}
char s[maxn], x[maxd], y[maxd];
int dp[2][maxn * maxn][2][2], n, d;
void add(int &x, int y){
	x += y;
	if(x >= mod) x -= mod;
}
void sub(int &x, int y){
	x -= y;
	if(x < 0) x += mod;
}
int solve(char *x){
	memset(dp[0], 0, sizeof dp[0]);
	dp[0][0][1][0] = 1;
	for(int i = 1; i <= d; i += 1){
		int u = (i & 1) ^ 1, v = i & 1;
		memset(dp[v], 0, sizeof dp[v]);
		for(int j = 0; j < (int)t.size(); j += 1)
			for(int k = 0; k < 2; k += 1)
				for(int l = 0; l < 2; l += 1)
					for(int d = 0; d < 10; d += 1){
						int nj = 0, nk = 0, nl = 0;
						if(k == 1 and d > x[i] - '0') continue;
						nk = k == 1 and d == x[i] - '0';
						if(l == 0) nj = go(j, d + '0');
						nl = l or t[nj].leaf;
						add(dp[v][nj][nk][nl], dp[u][j][k][l]);
					}
	}
	int res = 0;
	int u = d & 1;
	for(int j = 0; j < (int)t.size(); j += 1)
		for(int k = 0; k < 2; k += 1)
				add(res, dp[u][j][k][1]);
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> s >> (x + 1) >> (y + 1);
	n = strlen(s), d = strlen(x + 1);
	x[d] -= 1;
	for(int i = d; i >= 1; i -= 1)
		if(x[i] < '0'){
			x[i] += 10;
			x[i - 1] -= 1;
		}
	for(int i = 0; i + d / 2 <= n; i += 1)
		add_string(string(s).substr(i, d / 2));
	cout << (solve(y) - solve(x) + mod) % mod;
	return 0;
}