#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(){cout << -1; exit(0);}
constexpr int maxn = 240000;
LL d[maxn], s[maxn];
int main(){
	ios::sync_with_stdio(false);
	LL h, ans = (LL)1E18;
	int n;
	cin >> h >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> d[i];
		s[i] = s[i - 1] + d[i];
	}
	for(int i = 1; i <= n; i += 1){
		LL hh = h + s[i];
		if(hh <= 0) ans = min(ans, (LL)i);
		if(hh > 0 and s[n] < 0) ans = min(ans, i + (hh + -s[n] - 1) / -s[n] * n);
	}
	if(ans == (LL)1E18) no();
	cout << ans;
}