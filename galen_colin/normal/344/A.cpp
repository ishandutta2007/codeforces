#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    int tot = n;
    string last, s;
    cin >> last;
    for (int i = 0; i < n-1; i++) {
      cin >> s;
      if (s.at(0) != last.at(1)) tot--;
      last = s;
    }
    cout << tot << endl;
}