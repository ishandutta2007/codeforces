#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii; 

int n, m, k;
pii e[1010];
int fa[2][1010], key[2][1010], people[2][1010];
char buf[20];
map <string, int> MP;
int tot = 0;

string read(){
	scanf("%s", buf);
	return buf;
}

int get_id(string s){
	if (MP.count(s)) return MP[s];
	return MP[s] = tot++;
}

int find(int x, int fa[]){
	return fa[x] == x ? x : fa[x] = find(fa[x], fa);
}

void solve(int p){
	for (int i = 0; i < k; i++){
		string name = read();
		int id = get_id(name), now, m;
		scanf("%d%d", &now, &m);
		people[p][id] = now;
		for (int j = 0; j < m; j++){
			int x; scanf("%d", &x);
			key[p][x] = now;
		}
	}
	for (int i = 1; i <= n; i++){
		fa[p][i] = i;
	}
	int flag = 1;
	while (flag){
		flag = 0;
		for (int i = 1; i <= m; i++){
			int id = find(key[p][i], fa[p]);
			int x = fa[p][e[i].fi], y = fa[p][e[i].se];
			if ((x == id || y == id) && x != y){
				for (int j = 1; j <= n; j++){
					if (fa[p][j] == x) fa[p][j] = y;
				}
				flag = 1;
			}
		}
	}
}

int check(){
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if ((fa[0][i] == fa[0][j]) != (fa[1][i] == fa[1][j])) return 0;
		}
	}
	for (int i = 0; i < k; i++){
		if (fa[0][people[0][i]] != fa[0][people[1][i]]) return 0;
	}
	for (int i = 1; i <= m; i++){
		if (fa[0][key[0][i]] != fa[0][key[1][i]]) return 0;
	}
	return 1;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &e[i + 1].fi, &e[i + 1].se);
	}
	solve(0), solve(1);
	printf(check() ? "YES\n" : "NO\n");
	return 0;
}