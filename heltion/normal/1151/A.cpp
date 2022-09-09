#include<bits/stdc++.h>
using LL = long long;
using namespace std;
constexpr int maxn = 100;
char s[maxn];
int dis(char a, char b){
	int aa = a - 'A', bb = b - 'A';
	if(aa > bb) swap(aa, bb);
	return min(bb - aa, aa + 26 - bb);
}
int main(){
	ios::sync_with_stdio(false);
	int n, ans = 1e9;
	cin >> n >> s;
	for(int i = 0; i + 4 <= n; i += 1)
		ans = min(ans, dis(s[i], 'A') + dis(s[i + 1], 'C') + dis(s[i + 2], 'T') + dis(s[i + 3], 'G'));
	cout << ans;
}