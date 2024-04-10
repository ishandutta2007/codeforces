#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    string s;
    cin >> s;

    int cp = 1, mcp = 1;
    char last = s.at(0);
    for (int i = 1; i < s.length(); i++) {
      if (s.at(i) == last) {
        cp++;
        mcp = max(mcp, cp);
      } else {
        cp = 1;
        last = s.at(i);
      }
    }

    if (mcp > 6) cout << "YES";
    else cout << "NO";
    cout << endl;
}