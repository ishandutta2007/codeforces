#include<bits/stdc++.h>

using namespace std;
map<string, int> mp;
int main() {
int n; cin >> n;
int res = 0;
for(int i = 0; i < n; i++) {
string s; cin >> s; res = max(res, ++mp[s]);
}
cout << res << '\n';
}