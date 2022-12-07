#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int p[100];
string s;

bool isVow(char c) {
    return c == 'a' || c == 'e' || c == 'i' ||
        c == 'o' || c == 'u' || c == 'y';
}

int main() {
    cin >> n;
    forn(i, n) cin >> p[i];
    getline(cin, s);
    forn(i, n) {
        getline(cin, s);
        int cnt = 0;
        for (char c : s) if (isVow(c)) {
            ++cnt;
        }
        if (cnt != p[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}