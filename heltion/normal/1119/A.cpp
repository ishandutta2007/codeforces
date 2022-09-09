#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 360000;
void no(){
	cout << "NO";
	exit(0);
}
int c[maxn];
vector<int> v[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i += 1)
		cin >> c[i];
	for(int i = 1; i <= n; i += 1){
		if(c[i] != c[1]) ans = max(ans, i - 1);
		if(c[i] != c[n]) ans = max(ans, n - i);
	}
	cout << ans;
}