// Author: Heltion
// Date: 2019-04-26
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
char s[maxn];
int f[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n >> s;
	for(int i = 1; i < 10; i += 1) cin >> f[i];
	for(int i = 0, ok = 0; i < n; i += 1){
		if(f[s[i] - '0'] > s[i] - '0'){
			ok = 1;
			s[i] = f[s[i] - '0'] + '0';
		}
		else if(f[s[i] - '0'] < s[i] - '0' and ok) break;
	}
	cout << s;
	return 0;
}