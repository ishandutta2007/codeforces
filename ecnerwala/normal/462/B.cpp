#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll cnt[30];
int main() {
ll n, k; cin >> n >> k;
string s; cin >> s;

for(int i = 0; i < n; i++) cnt[s[i] - 'A'] ++;
sort(cnt, cnt + 26);
reverse(cnt, cnt + 26);
ll res = 0;
for(int i = 0; i < 26; i++) {
ll v = min(cnt[i], k);
res += v * v;
k -= v;
}
cout << res << '\n';
}