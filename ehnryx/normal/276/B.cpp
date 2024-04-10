#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const ll INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

The story of lame:

int cnt[26];
memset(cnt, 0, sizeof(cnt));
string s;
cin >> s;
for (int i = 0; i < s.size(); i++) {
	cnt[s[i]-'a']++;
}
int odd = 0;
for (int i = 0; i < 26; i++) {
	if (cnt[i]%2) 
		odd++;
}
if (!odd || odd%2) cout << "First" << endl;
else cout << "Second" << endl;


The End