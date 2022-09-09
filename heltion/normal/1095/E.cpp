#include<bits/stdc++.h>
using namespace std;
#define maxn 1200000
char c[maxn];
int s[maxn], m[maxn];
int main(){
	int n, ans = 0;
	cin >> n >> c + 1;
	for(int i = 1; i <= n; i += 1)
		if(c[i] == '(') s[i] = s[i - 1] + 1;
		else s[i] = s[i - 1] - 1;
	m[n + 1] = maxn;
	for(int i = n; i >= 1; i -= 1){
		m[i] = min(s[i], m[i + 1]);
	} 
	if(s[n] == 2)
		for(int i = 1; i <= n; i += 1)
			if(s[i] < 0) break;
			else if(m[i] >= 2 && c[i] == '(') ans += 1;
	if(s[n] == -2)
		for(int i = 1; i <= n; i += 1){
			if(m[i] >= -2 && c[i] == ')') ans += 1;
			if(s[i] < 0) break;
		}
	cout << ans;
}