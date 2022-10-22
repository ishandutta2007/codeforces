#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000009;
const string son = "ACGT";

char buf[20];
int T[110][4], fa[110], val[110], maxlen[110];
int fail[110][4];
long long f[1010][110][20];
string pre[110];
int tot;

string read(){scanf("%s", buf); return buf;}

int key(char c){return c == 'A' ? 0 : c == 'C' ? 1 : c == 'G' ? 2 : 3;}

int newnode(int f, int v){
	fa[tot] = f, val[tot++] = v;
	return tot - 1;
}

void Insert(string &s){
	int n = s.length(), now = 0;
	for (int i = 0; i < n; i++){
		if (T[now][key(s[i])] == -1) T[now][key(s[i])] = newnode(now, key(s[i]));
		now = T[now][key(s[i])];
	}
	maxlen[now] = n;
}

void get_pre(){
	for (int i = 1; i < tot; i++){
		pre[i] = pre[fa[i]] + son[val[i]];
	}
}

void get_maxlen(){
	int flag = 1;
	while (flag){
		flag = 0;
		for (int i = 0; i < tot; i++){
			for (int j = 0; j < tot; j++){
				int n = pre[i].size(), m = pre[j].size();
				if (m > n && pre[j].substr(m - n, m) == pre[i]){
					if (maxlen[j] < maxlen[i]) maxlen[j] = maxlen[i], flag = 1;
				}
			}
		}
	}
}

void get_fail(){
	for (int i = 0; i < tot; i++){
		for (int q = 0; q < 4; q++){
			string s = pre[i] + son[q];
			int maxj = 0, f = 0;
			for (int j = 1; j < tot; j++){
				string t = pre[j];
				int n = t.size(), m = s.size();
				if (m >= n && s.substr(m - n, n) == t){
					if (n > maxj) maxj = n, f = j;
				}
			}
			fail[i][q] = f;
		}
	}
}

int main(){
	memset(T, -1, sizeof(T));
	fa[tot] = -1, val[tot] = -1, pre[tot++] = "";
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		string s = read();
		Insert(s);
	}
	get_pre(), get_maxlen(), get_fail();
	f[0][0][0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < tot; j++){
			for (int k = 0; k <= 10; k++){
				if (f[i][j][k] == 0) continue;
				for (int q = 0; q < 4; q++){
					int ii = i + 1, jj = fail[j][q], kk = maxlen[jj] >= k + 1 ? 0 : k + 1;
					f[ii][jj][kk] = (f[ii][jj][kk] + f[i][j][k]) % mod;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < tot; i++){
		ans = (ans + f[n][i][0]) % mod;
	}
	printf("%I64d\n", ans);
	return 0;
}