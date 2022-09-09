#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200000;
int f[maxn], g[maxn];
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin >> (s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i += 1){
		int x = 0;
		for(int j = i; j <= n; j += 1){
			if((x >> (s[j] - 'a')) & 1) break;
			x |= 1 << (s[j] - 'a');
			f[x] = 1;
		}
	}
	for(int i = 1; i < (1 << 20); i += 1){
		if(f[i]){
			g[i] = 0;
			for(int j = 0; j < 20; j += 1) if((i >> j) & 1) g[i] += 1;
		}
		else{
			for(int j = 0; j < 20; j += 1)
				if((i >> j) & 1)
					g[i] = max(g[i ^ (1 << j)], g[i]);
		}
	}
	int ans = 0;
	for(int i = 0; i < (1 << 20); i += 1)
		ans = max(g[i] + g[((1 << 20) - 1) ^ i], ans);
	cout << ans;
}