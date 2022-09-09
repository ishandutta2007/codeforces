#include<bits/stdc++.h>
using namespace std;
void no(){cout << -1; exit(0);}
constexpr int maxn = 500000;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, ans = 0, pans = 0;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		cin >> a[i];
		a[i + n] = a[i];
	}
	for(int i = 0; i < 2 * n; i += 1)
		if(a[i]) ans = max(ans, pans += 1);
		else pans = 0;
	cout << ans;
}