#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, pos;

int main() {
    cin >> n >> pos;
    n %= 6;
    while (n) {
        if (n % 2 == 0) {
            if (pos == 2) pos = 1;
            else if (pos == 1) pos = 2;
        } else {
            if (pos == 0) pos = 1;
            else if (pos == 1) pos = 0;
        }
        --n;
    }
    cout << pos << endl;
    return 0;
}