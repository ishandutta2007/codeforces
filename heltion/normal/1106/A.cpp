#include<bits/stdc++.h>
using namespace std;
#define maxn 540
char s[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1)
		cin >> s[i] + 1;
	int ans = 0;
	for(int i = 1; i <= n; i += 1)
		for(int j = 1; j <= n; j += 1)
			if(s[i][j] == 'X')
			if(s[i - 1][j + 1] == 'X')
			if(s[i + 1][j - 1] == 'X')
			if(s[i + 1][j + 1] == 'X')
			if(s[i - 1][j - 1] == 'X')
			ans += 1;
	cout << ans;
}