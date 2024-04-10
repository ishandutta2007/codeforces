#include <bits/stdc++.h>
using namespace std;

const int K = 10;
const int M = 55;
const int N = 26005;
const int mod = 1000000007;

int iter, chk[N], tree[N][K], link[N], mem[M][N][2][2];

inline void insert(string s){
	int root = 0;
	for(auto ch : s){
		int v = ch - '0';
		if(tree[root][v] == -1){
			tree[root][v] = ++iter;
		}
		root = tree[root][v];
	}
	chk[root] = 1;
}

void createLinks(){
	queue<int> qu;
	link[0] = 0;
	for(int i = 0; i < K; i++){
		if(tree[0][i] == -1){
			tree[0][i] = 0;
		}else{
			link[tree[0][i]] = 0;
			qu.push(tree[0][i]);
		}
	}
	while(!qu.empty()){
		int v = qu.front(); qu.pop();
		for(int i = 0; i < K; i++){
			if(tree[v][i] == -1){
				int w = v;
				while(tree[w][i] == -1){
					w = link[w];
				}
				tree[v][i] = tree[w][i];
			}else{
				int w = link[v];
				while(tree[w][i] == -1){
					w = link[w];
				}
				qu.push(tree[v][i]);
				link[tree[v][i]] = tree[w][i];
			}
		}
	}
}

int d, len, n;
string s, x, y;

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int dp(string &dig, int i, int state, int reached, int flg){
	if(i == d){
		return reached;
	}
	int &ret = mem[i][state][reached][flg];
	if(ret != -1)return ret;
	ret = 0;
	int dg = dig[i] - '0';
	for(int j = 0; j < K; j++){
		if(flg && j > dg)break;
		int nflg = flg && (j == dg);
		int nstate = tree[state][j];
		add(ret, dp(dig, i + 1, nstate, reached|chk[nstate], nflg));
	}
	return ret;
}

bool check(string t){
	int root = 0;
	for(auto ch : t){
		int v = ch - '0';
		root = tree[root][v];
		if(chk[root])return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> x >> y;
	d = (int)x.size();

	iter = 0;
	len = d >> 1;
	n = (int)s.size();
	memset(chk, 0, sizeof(chk));
	memset(tree, -1, sizeof(tree));
	for(int i = 0; i + len <= n; i++){
		insert(s.substr(i, len));
	}
	createLinks();
	int ans = 0;
	memset(mem, -1, sizeof(mem));
	add(ans, dp(y, 0, 0, 0, 1));
	memset(mem, -1, sizeof(mem));
	add(ans, mod - dp(x, 0, 0, 0, 1));
	if(check(x))add(ans, 1);
	cout << ans << '\n';

	return 0;
}