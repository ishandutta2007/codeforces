#include<bits/stdc++.h>
using namespace std;
bool is_vowel(char c) {
return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i';
}
int main() {
string s; cin >> s;
for (int i = 0; i < s.size(); i++) {
if (is_vowel(s[i]) || s[i] == 'n') continue;
if (i+1 == s.size() || !is_vowel(s[i+1])) {
cout << "NO\n"; return 0;
}
}
cout << "YES\n"; return 0;
}