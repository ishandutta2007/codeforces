#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp[2];
typedef long long LL;
#define maxn 320000
int a[maxn], s[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i]; 
	}
	for(int i = 0; i <= n; i += 1)
		mp[i & 1][s[i]] += 1;
	LL ans = 0;
	for(int i = 0; i < 2; i += 1)
		for(const auto &p : mp[i])
			ans += 1LL * (p.second - 1) * p.second / 2;
	cout << ans;
}