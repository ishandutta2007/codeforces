#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 120;
char s[maxn];
int main(){
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n >> s;
		int ans = n - 1;
		for(int i = 0; i < n; i += 1)
			if(s[i] == '>') ans = min(ans, i);
			else ans = min(ans, n - i - 1);
		cout << ans << endl;
	}
}