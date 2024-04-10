#include<bits/stdc++.h>
using namespace std;
#define maxt 120000
#define maxm 50
unordered_map<string, int> id;
unordered_set<int> um;
int t[maxt];
string s[maxt];
const int maxn = 50;

void clique(int n, int mat[][maxn], int num, int U[], int size, int C[], int& _max, int ok) {
    int i, j, k, tmp[maxn];
    fill(tmp, tmp + maxn, 0);
    if (num == 0) {
        if (size > _max) { ok = 1; _max = size; }
        return;
    }
    for (i = 0; i < num && !ok; ++i) {
        if (size + num  - i <= _max) return;
        if (size + C[U[i]] <= _max) return;
        for (k = 0, j = i + 1; j < num; ++j) if (mat[U[i]][U[j]])
            tmp[k++] = U[j];
        clique(n, mat, k, tmp, size + 1, C, _max, ok);
    }
}

int U[maxn], C[maxn];
int max_clique(int n, int mat[][maxn]) {
    int i, j, k, _max;
    for (_max = 0, i = n - 1; i >= 0; --i) {
        for (k = 0, j = i + 1; j < n; ++j) if (mat[i][j])
            U[k++] = j;
        clique(n, mat, k, U, 1, C, _max, 0);
        C[i] = _max;
    } return _max;
}
int mat[maxm][maxm];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i += 1){
		cin >> t[i];
		if(t[i] == 2){
			cin >> s[i];
			if(id.count(s[i]) == 0) id[s[i]] = id.size() - 1;
		}
	}
	for(int i = 0; i < m; i += 1)
		for(int j = 0; j < m; j += 1) mat[i][j] = 1;
	for(int i = n; i >= 1; i -= 1){
		if(t[i] == 2) um.insert(id[s[i]]);
		else{
			for(auto s : um)
				for(auto t : um)
					mat[s][t] = mat[t][s] = 0;
			um.clear();
		}
	}
	cout << max_clique(m, mat);
}