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

	int n = nxt();
	int m = nxt();
	int ans = 0;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < m - 1; j++){
			string st = "";
			st = st + a[i][j];
			st = st + a[i][j + 1];
			st = st + a[i + 1][j];
			st = st + a[i + 1][j + 1];
			sort(all(st));
			if (st == "acef")
				ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}