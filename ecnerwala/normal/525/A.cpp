#include<bits/stdc++.h>

using namespace std;
int cnt[26];
int main() {
int n; cin >> n; n--;
string s; cin >> s;
int res = 0;
for(int i = 0; i < n; i++) {
(cnt[s[2 * i] - 'a'] ++);
if(cnt[s[2 * i + 1] - 'A']) {
cnt[s[2 * i + 1] - 'A'] --;
} else res++;
}
cout << res << '\n';
return 0;
}