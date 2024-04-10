#include<bits/stdc++.h>
using namespace std;
#define maxn 240000
char s[maxn];
int ans[26], cnt[26];
int main(){
	int n, k;
	cin >> n >> k >> s;
	for(int i = 0; i < n; i += 1){
		for(int j = 0; j < 26; j += 1) if(j != s[i] - 'a') cnt[j] = 0;
		cnt[s[i] - 'a'] += 1;
		if(cnt[s[i] - 'a'] >= k) cnt[s[i] - 'a'] = 0, ans[s[i] - 'a'] += 1;
	}
	cout << *max_element(ans, ans + 26);
}