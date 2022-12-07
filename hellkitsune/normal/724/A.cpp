#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int M[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string a, b;

int calc(string s) {
    if (s[0] == 'm') return 0;
    else if (s[0] == 't' && s[1] == 'u') return 1;
    else if (s[0] == 'w') return 2;
    else if (s[0] == 't') return 3;
    else if (s[0] == 'f') return 4;
    else if (s[1] == 'a') return 5;
    return 6;
}

int main() {
    cin >> a >> b;
    int dif = (calc(b) - calc(a) + 7) % 7;
    forn(i, 11) {
        int cur = M[i] % 7;
        if (cur == dif) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}