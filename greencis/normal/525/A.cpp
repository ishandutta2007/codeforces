#include <bits/stdc++.h>
using namespace std;

map<char,int> mp;
int n,ans;
char s[500005];

int main() {
 cin >> n>> s;
 for (int i=0; i<n-1; ++i) {
  ++mp[s[i+i]-32];
  if (mp[s[i+i+1]]) --mp[s[i+i+1]];
  else ++ans;
 }cout << ans; return 0;
}