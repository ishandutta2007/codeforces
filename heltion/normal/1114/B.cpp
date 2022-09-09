#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
auto no = [](){cout << "NO"; exit(0);};
auto read = [](){int x; cin >> x; return x;};
#define maxn 240000
int a[maxn], b[maxn], c[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		b[i] = i;
	}
	sort(b + 1, b + n + 1, [&](const int &x, const int &y){
		return a[x] > a[y];
	});
	LL ans = 0;
	for(int i = 1; i <= m * k; i += 1){
		ans += a[b[i]];
		c[b[i]] = 1;
	}
	cout << ans << endl;
	int s = 0, x = 0;
	for(int i = 1; i <= n && x + 1 < k; i += 1){
		s += c[i];
		if(s == m){
			cout << i << " ";
			x += 1;
			s = 0;
		}
	}
}