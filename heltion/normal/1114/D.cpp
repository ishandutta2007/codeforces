#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
auto no = [](){cout << "NO"; exit(0);};
auto read = [](){int x; cin >> x; return x;};
#define maxn 6000
int a[maxn], b[maxn];
int f[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, m = 0, c, L = 0;
	cin >> n;
	while(n --){
		cin >> c;
		if(c != L) a[m += 1] = c;
		L = c;
	}
	for(int i = 1; i <= m; i += 1) b[i] = a[1 + m - i];
	for(int i = 1; i <= m; i += 1)
		for(int j = 1; j <= m; j += 1){
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if(a[i] == b[j]) f[i][j] = max(f[i][j], 1 + f[i - 1][j - 1]);
		}
	int ans = 0;
	for(int i = 0; i <= m - 1; i += 1)
		ans = max(ans, f[i][m - 1 - i]);
	cout << m - 1 - ans;
}