#include<bits/stdc++.h>

using namespace std;

string s;
int k;

int main() {
cin >> s >> k;
int res = (k + 1) / 2; // last letter of s, all of k
for(int i = 0; i < int(s.size()); i++) {
for(int l = res; i + l + l <= k + s.size(); l++) {
bool isGood = true;
for(int j = i; j < i + l && j + l < int(s.size()); j++) {
if(s[j] != s[j + l]) isGood = false;
}
if(isGood) res = max(res, l);
}
}
cout << res * 2 << '\n';
}