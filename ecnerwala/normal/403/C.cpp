#include<iostream>
#include<cstdio>

using namespace std;

int N;
int A[3000][3000];

bool vis[3000];

void dfs(int a) {
	vis[a] = true;
	for(int i = 0; i < N; i++) {
		if(A[a][i] && !vis[i]) {
			dfs(i);
		}
	}
}

bool go() {
	for(int i = 0; i < N; i++) vis[i] = false;
	dfs(0);
	for(int i = 0; i < N; i++) if(!vis[i]) return false;
	for(int i = 0; i < N; i++) vis[i] = false;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < i; j++) {
			int tmp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = tmp;
		}
	}
	dfs(0);
	for(int i = 0; i < N; i++) if(!vis[i]) return false;
	return true;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf((go() ? "YES\n" : "NO\n"));
	return 0;
}