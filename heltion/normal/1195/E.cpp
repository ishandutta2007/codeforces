//Author: Heltion
//Date: 07-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 3200;
void no(){cout << "NO"; exit(0);}
int h[maxn][maxn], hm[maxn][maxn];
int q[maxn], head, tail;
void insert(int x){
	while(head < tail and q[tail - 1] > x) tail -= 1;
	q[tail ++] = x;
}
int begin(){
	return q[head];
}
void erase(int x){
	if(head < tail and x == q[head]) head += 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	LL g, x, y, z;
	cin >> g >> x >> y >> z;
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= m; j += 1){
			h[i][j] = g;
			g = (g * x + y) % z;
		}
	for(int i = 1; i <= n; i += 1){
		head = tail = 0;
		for(int j = 1; j < b; j += 1) insert(h[i][j]);
		for(int j = b; j <= m; j += 1){
			insert(h[i][j]);
			hm[i][j - b + 1] = begin();
			erase(h[i][j - b + 1]);
		}
	}
	LL ans = 0;
	for(int j = 1; j <= m - b + 1; j += 1){
		head = tail = 0;
		for(int i = 1; i < a; i += 1) insert(hm[i][j]);
		for(int i = a; i <= n; i += 1){
			insert(hm[i][j]);
			ans += begin();
			erase(hm[i - a + 1][j]);
		}
	}
	cout << ans;
	return 0;
}