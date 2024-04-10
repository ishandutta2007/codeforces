#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define maxn 120000
LL c[26][maxn];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		string s;
		cin >> s;
		for(LL j = 0, k = 0, cnt = 0; j < s.size(); j += 1){
			if(s[j] != k + 'a'){
				k = s[j] - 'a';
				c[k][i] = max(cnt = 1, c[k][i]);
			}
			else{
				k = s[j] - 'a';
				c[k][i] = max(cnt += 1, c[k][i]);
			}
		}
		LL p = 0;
		while(p + 1 < s.size() and s[p + 1] == s[p]) p += 1;
		int k = s[0] - 'a';
		if(c[k][i - 1]) c[k][i] = max(p + 2, c[k][i]);
		
		LL q = s.size() - 1;
		while(q and s[q - 1] == s[q]) q -= 1;
		k = s[s.size() - 1] - 'a';
		if(c[k][i - 1]) c[k][i] = max(s.size() - q + 1, c[k][i]);
		if(q and s[0] == k + 'a') c[k][i] = max(s.size() - q + p + 2, c[k][i]);
		if(not q and c[k][i - 1])
			c[k][i] = min((LL)(1E9), max(s.size() * (c[k][i - 1] + 1) + c[k][i - 1], c[k][i]));
		for(int j = 0; j < 26; j += 1) if(c[j][i - 1]) c[j][i] = max(1LL, c[j][i]);
		
		//for(int i = 1; i <= n; i += 1){
		//	for(int j = 0; j < 26; j += 1)
		//		cout << c[j][i] << " ";
		//	cout << endl;
		//}
	}
	LL ans = 0;
	
	for(int i = 0; i < 26; i += 1) ans = max(ans, c[i][n]);
	cout << ans; 
}