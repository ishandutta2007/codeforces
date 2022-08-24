#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 555;
char a[N][N];

int main(){

	int n = nxt();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j)
				continue;
			a[i][j] = 1;
		}
	}
	int m = nxt();
	while (m--){
		int u = nxt() - 1, v = nxt() - 1;
		a[u][v] = a[v][u] = 0;
	}

	vector<int> color(n);
	vector<vector<int>> ar(n);
	for (int i = 0; i < n; i++){
		for (int j =0 ; j < n; j++){
			if (a[i][j])
				ar[i].push_back(j);
		}
	}
	set<vector<int>> S;
	for (int i = 0; i < n; i++){
		if (!ar[i].empty()){
			S.insert(ar[i]);
		}
	}

	if (S.size() > 2){
		puts("No");
	} else if (S.size() == 0){
		puts("Yes");
		for (int i = 0; i < n; i++)
			printf("b");
		puts("");
	} else {
		puts("Yes");
		for (int i = 0; i < n; i++){
			if (ar[i].empty())
				printf("b");
			else if (ar[i] == *S.begin())
				printf("a");
			else
				printf("c");
		}
		puts("");
	}

	return 0;
}