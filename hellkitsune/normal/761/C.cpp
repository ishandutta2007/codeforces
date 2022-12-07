#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

bool isDig(char c) {
    return c >= '0' && c <= '9';
}

bool isChar(char c) {
    return c >= 'a' && c <= 'z';
}

bool isSpe(char c) {
    return c == '#' || c == '*' || c == '&';
}

const int INF = int(1e9);

int d[8], nd[8];

int n, m;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    forn(i, 8) d[i] = INF;
    d[0] = 0;
    forn(_, n) {
        forn(i, 8) nd[i] = INF;
        cin >> s;
        forn(i, m) {
            int dist = i;
            if (m - dist < dist) {
                dist = m - dist;
            }
            int b = 0;
            if (isDig(s[i])) b = 1;
            else if (isChar(s[i])) b = 2;
            else if (isSpe(s[i])) b = 4;
            forn(i, 8) {
                nd[i | b] = min(nd[i | b], d[i] + dist);
            }
        }
        forn(i, 8) d[i] = nd[i];
    }
    cout << d[7] << endl;
    return 0;
}