#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

// #define error(arg...){vector<string>_v=split(#arg,',');err(_v.begin(),arg);}
// vector<string> split(const string& s,char c){vector<string> v;stringstream ss(s);
// string x;while(getline(ss,x,c))v.push_back(move(x));return v;}
// void err(vector<string>::iterator it){}template<typename T,typename...Args>
// void err(vector<string>::iterator it,T a, Args... args){cerr<<it->
// substr((*it)[0]==' ',it->length())<<" = "<<a<<'\n';err(++it, args...);}

#define MAXN 300013
#define BITS 30
int N;
int A[MAXN];
int B[MAXN];
int G[MAXN * BITS][2], M = 1;
int sz[MAXN * BITS];

void add_trie(int x) {
	int cur = 0;
	for (int i = BITS - 1; i >= 0; i--) {
		int d = (x & (1<<i)) ? 1 : 0;
		if (G[cur][d] == -1)
			G[cur][d] = M++;
		cur = G[cur][d];
		sz[cur]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	memset(G, -1, sizeof G);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		add_trie(B[i]);
	}

	for (int i = 0; i < N; i++) {
		int res = 0;
		int cur = 0;
		for (int j = BITS - 1; j >= 0; j--) {
			int d = (A[i] & (1<<j)) ? 1 : 0;
			if (G[cur][d] != -1 && sz[G[cur][d]])
				cur = G[cur][d];
			else
				cur = G[cur][!d], res += (1<<j);
			sz[cur]--;
		}
		cout << res << ' ';
	}

	cout << endl;
	return 0;
}