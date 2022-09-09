#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int maxn = 1200;
void no(){ cout << "NO"; exit(0); }
LL a[maxn], b[maxn];
int main(){
	ios::sync_with_stdio(false);	
	LL n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i += 1) a[i] = n / m;
	for(int i = 1; i < m; i += 1) if(i <= n % m) a[i] += 1;
	for(int i = 0; i < m; i += 1) b[i * i % m] += a[i];
	LL ans = 0;
	for(int i = 0; i < m; i += 1) ans += i ? b[i] * b[m - i] : b[i] * b[i];
	cout << ans;
}