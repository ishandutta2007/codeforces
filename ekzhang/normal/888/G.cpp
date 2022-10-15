#include <bits/stdc++.h>
using namespace std;

#define error(arg...){vector<string>_v =split(#arg,',');err(_v.begin(),arg);}
vector<string> split(const string& s,char c){vector<string> v;stringstream ss(s);
string x;while(getline(ss,x,c))v.push_back(move(x));return v;}
void err(vector<string>::iterator it){}template<typename T,typename...Args>
void err(vector<string>::iterator it,T a, Args... args){cerr<<it->
substr((*it)[0]==' ',it->length())<<" = "<<a<<'\n';err(++it, args...);}

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
#define K 30
#define MAXM (K*MAXN)
int N;
int G[MAXM][2];
int M = 1;
LL ans;

void add_trie(int x) {
	int n = 0;
	for (int i = K - 1; i >= 0; i--) {
		bool b = x & (1<<i);
		if (G[n][b] == -1) G[n][b] = M++;
		n = G[n][b];
	}
}

int dfs(int n, int m, int k) {
	if (k == -1) return 0;
	int ret = (1<<k);
	for (int b = 0; b < 2; b++) {
		if (~G[n][b] && ~G[m][b]) {
			ret = min(ret, dfs(G[n][b], G[m][b], k-1));
		}
	}
	if (ret == (1<<k)) {
		if (~G[n][0]) ret += dfs(G[n][0], G[m][1], k-1);
		else ret += dfs(G[n][1], G[m][0], k-1);
	}
	return ret;
}

void go(int n, int k=K-1) {
	if (~G[n][0] && ~G[n][1]) {
		ans += (1<<k);
		ans += dfs(G[n][0], G[n][1], k-1);
	}
	if (~G[n][0]) go(G[n][0], k-1);
	if (~G[n][1]) go(G[n][1], k-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	memset(G, -1, sizeof G);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		add_trie(X);
	}

	go(0);

	cout << ans << endl;
	return 0;
}