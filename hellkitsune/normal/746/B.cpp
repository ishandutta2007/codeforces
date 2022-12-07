#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s, t;

int main() {
    cin >> n >> s;
    forn(i, n) {
        if ((i ^ n) & 1) {
            t += s[i];
        } else {
            t = string(1, s[i]) + t;
        }
    }
    cout << t << endl;
    return 0;
}