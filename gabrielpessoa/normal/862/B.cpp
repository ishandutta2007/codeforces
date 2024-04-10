#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

vector<int> graph[SIZE];
int cor[SIZE];

long long tipo1 = 1;

void dfs(int pos) {
    //printf("DFS em %d\n", pos);
    for(int i = 0; i < graph[pos].size(); i++) {
        int v = graph[pos][i];
        if(!cor[v]) {
            cor[v] = -cor[pos];
            if(cor[v] == 1) {
                tipo1++;
            }
            dfs(v);
        }
    }
}

int main() {
    long long n;
	int u, v;
	scanf("%I64d", &n);
	for(int i = 1; i < n; i++) {
	    scanf("%d %d", &u, &v);
	    graph[u].push_back(v);
	    graph[v].push_back(u);
	}
	cor[1] = 1;
	dfs(1);
	//cout << tipo1 << endl;
	long long resultado = tipo1 * (n-tipo1) - (n-1);
	cout << resultado << endl;
	return 0;
}