#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

char s[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    char cur = 'a';
    for (int i = 0; s[i] && cur <= 'z'; ++i) {
        if (s[i] <= cur) {
            s[i] = cur;
            ++cur;
        }
    }
    if (cur <= 'z') cout << -1 << endl;
    else cout << s << endl;
}