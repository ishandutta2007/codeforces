#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void no(const char *s = "NO"){cout << s;exit(0);} 
constexpr int maxn = 240000;
int s[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, b, a, p, na;
	cin >> n >> b >> a;
	for(int i = 1; i <= n; i += 1) cin >> s[i];
	for(p = 0, na = a ; p < n; p += 1){
		if(not na and not b) break;
		if(not na) b -= 1, na = min(a, na + s[p + 1]);
		else if(not b or not s[p + 1] or a == na) na -= 1;
		else b -= 1, na += 1;
	}
	cout << p;
}