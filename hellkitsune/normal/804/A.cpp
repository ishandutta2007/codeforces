#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;

int main() {
    cin >> n;
    if (n % 2 == 0) {
        cout << (n - 2) / 2 << endl;
    } else {
        cout << (n - 1) / 2 << endl;
    }
    return 0;
}