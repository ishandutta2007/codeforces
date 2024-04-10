#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(const char *s = "NO"){cout << s;exit(0);} 
constexpr int maxn = 10000000 + 1;
int a[maxn], p[maxn];
int main(){
	ios::sync_with_stdio(false);
	LL ans = 1e18, ansi, ansj;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		if(p[a[i]] and ans > a[i]) ans = a[i], ansi = p[a[i]], ansj = i;
		p[a[i]] = i;
	}
	for(int d = 1; d < maxn; d += 1)
		for(int x = 0, y = d; y < maxn; y += d) if(p[y]){
			if(x == 0) x = y;
			else{
				if(ans > 1LL * x * y / d) ans = 1LL * x * y / d, ansi = p[x], ansj = p[y];
			}
		}
	if(ansi > ansj) swap(ansi, ansj);
	cout << ansi << " " << ansj;
}