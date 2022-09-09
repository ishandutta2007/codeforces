#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 600000
char s[maxn];
void no(){
	cout << -1;
	exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	int n = strlen(s);
	int L = -1, R = -1;
	for(int i = 0; i < n; i += 1){
		if(s[i] == '['&& L == -1) L = i;
		if(s[i + 1] == ']') R = i;
	}
	if(L == -1 || R == -1 || L > R) no();
	int l = L, r = R;
	while(l < R && s[l] != ':') l += 1;
	while(r > L && s[r] != ':') r -= 1;
	if(l >= r) no();
	int ans = 4;
	for(int i = l; i <= r; i += 1) ans += s[i] == '|'; 
	cout << ans;
}