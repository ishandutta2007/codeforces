#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, LL> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int n, m, a[105];
vector <int> v[105];

void Gao(int c){
	while (1){
		int flag = 0;
		for (int i = 0; i < n; i++)
		if (v[i].size() == a[i]) flag = 1;
		for (int i = 0; i < n; i++)
		if (v[i].size() != a[i])
			v[i].push_back(c);
		if (flag) break;
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		Gao(i);
	for (int i = 0; i < n; i++)
	if (v[i].size() != a[i]){
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < a[i]; j++)
			printf("%d ", v[i][j]);
		puts("");
	}
}