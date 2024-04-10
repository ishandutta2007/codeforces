#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
typedef long long LL;
LL s[maxn];
map<LL, int> mp;
int main(){
	int n, k;
	cin >> n >> k;
	LL f = (1LL << k) - 1, m = f >> 1;
	mp[0] = 1; 
	for(int i = 1; i <= n; i += 1){
		cin >> s[i];
		s[i] ^= s[i - 1];
		if(s[i] > m) s[i] ^= f;
		mp[s[i]] += 1;
	}
	LL ans = (LL)(n + 1) * n / 2;
	for(auto p : mp){
		LL x = p.second / 2, y = p.second - x;
		ans -= x * (x - 1) / 2 + y * (y - 1) / 2;
	}
	cout << ans;
}