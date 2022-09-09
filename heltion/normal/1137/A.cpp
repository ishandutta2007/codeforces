#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void no(){ cout << "NO"; exit(0);}
constexpr int maxn = 1000;
int r[maxn][maxn], c[maxn][maxn], a[maxn][maxn];
int rs[maxn], cs[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i += 1)
		for(int j = 0; j < m; j += 1){
			cin >> a[i][j];
			r[i][rs[i] ++ ] = a[i][j];
			c[j][cs[j] ++ ] = a[i][j];
		}
	for(int i = 0; i < n; i += 1){
		sort(r[i], r[i] + rs[i]);
		rs[i] = unique(r[i], r[i] + rs[i]) - r[i];
	}
	for(int i = 0; i < m; i += 1){
		sort(c[i], c[i] + cs[i]);
		cs[i] = unique(c[i], c[i] + cs[i]) - c[i];
	}
	for(int i = 0; i < n; i += 1){
		for(int j = 0; j < m; j += 1){
			int pr = lower_bound(r[i], r[i] + rs[i], a[i][j]) - r[i];
			int pc = lower_bound(c[j], c[j] + cs[j], a[i][j]) - c[j];
			cout << max(rs[i] - 1 - pr, cs[j] - 1 - pc) + max(pr, pc) + 1 << " ";
		}
		cout << endl;
	}
}