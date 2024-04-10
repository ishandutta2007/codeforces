#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) {
        int n; cin >> n;
        
        string s = "";
        for (int i = 0; i < 60; i++) s += 'a';
        cout << s << '\n';

        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            s[k] = 'a' + (((s[k]-'a')+1)%26);
            cout << s << '\n';
        }
    }
}