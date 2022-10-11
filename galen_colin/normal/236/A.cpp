#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    string s;
    cin >> s;
    bool b[26];
    memset(b, 0, sizeof(b));
    for(char c: s) {
      b[c - 'a'] = 1;
    }
    int t = 0;
    for (int i = 0; i < 26; i++) {
      t += b[i];
    }
    if (t % 2 == 0) cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
    cout << endl;
    exit(0);
}