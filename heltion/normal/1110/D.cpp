#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto no = [](){cout<<"No";exit(0);};
auto read = [](){LL x;cin>>x;return x;}; 
#define maxn 1200000
int a[maxn];
int f[maxn][3][3];
int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	while(n --) a[read()] += 1;
	for(int i = 0; i <= m; i += 1)
		for(int x = 0; x < 3; x += 1)
			for(int y = 0; y < 3; y += 1) f[i][x][y] = -maxn;
	f[0][0][0] = 0;
	int ans = 0;
	for (int i = 0; i <= m; i += 1)
		for (int u = 0; u <= 2; u += 1)	
			for (int v = 0; v <= 2; v += 1)
				if (f[i][u][v] >= 0){
					int r = a[i + 1] - u - v;
					for(int w = 0; w <= 2 && w <= r && v + w <= a[i + 2] && w <= a[i + 3];w += 1)
						f[i + 1][v][w] = max(f[i + 1][v][w], f[i][u][v] + (r - w) / 3 + w);
					ans = max(ans, f[i][u][v]);
				}
	cout << ans;
}