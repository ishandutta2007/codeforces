#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a, b;

int main() {
    cin >> a >> b;
    int cnt = 1;
    while (true) {
        if (a < cnt) {
            cout << "Vladik" << endl;
            return 0;
        }
        a -= cnt;
        ++cnt;
        if (b < cnt) {
            cout << "Valera" << endl;
            return 0;
        }
        b -= cnt;
        ++cnt;
    }
    return 0;
}