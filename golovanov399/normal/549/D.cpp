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

int f(char c){
	return (c == 'W') ? 1 : -1;
}

int main(){

	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<vector<int> > b(n, vector<int>(m, 0));
	int ans = 0;
	for (int i = n - 1; i >= 0; i--){
		for (int j = m - 1; j >= 0; j--){
			int dlt = f(a[i][j]) - b[i][j];
			if (!dlt) continue;
			for (int x = i; x >= 0; x--){
				for (int y = j; y >= 0; y--)
					b[x][y] += dlt;
			}
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}