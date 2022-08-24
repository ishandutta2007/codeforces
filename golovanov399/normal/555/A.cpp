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

int main(){

	int n = nxt(), k = nxt();
	vector<vector<int>> a(k);
	for (int i = 0; i < k; i++){
		int m = nxt();
		a[i].resize(m);
		for (int j = 0; j < m; j++)
			a[i][j] = nxt();
	}
	int ans = n - 1 + n - k;
	int i = 0;
	while (a[i][0] != 1)
		i++;
	int j = 1;
	while (j < a[i].size() && a[i][j] == j + 1){
		ans -= 2;
		j++;
	}
	printf("%d\n", ans);

	return 0;
}