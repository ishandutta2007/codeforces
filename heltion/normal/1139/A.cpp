#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 70000;
char s[maxn]; 
int main(){
	LL ans = 0;
	int n;
	cin >> n >> (s + 1);
	for(int i = 1; i <= n; i += 1)
		if((s[i] - '0') % 2 == 0) ans += i;
	cout << ans;
}