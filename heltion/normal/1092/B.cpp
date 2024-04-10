#include<bits/stdc++.h>
using namespace std;
#define maxn 120
int a[maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for(int i = 0; i < n; i += 2) ans += a[i + 1] - a[i];
	cout << ans;
}