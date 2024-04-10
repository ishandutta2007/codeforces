#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100];

int main() {
    cin >> n;
    forn(i, n) cin >> a[i];
    int flag = 0;
    for (int i = 1; i < n; ++i) {
        if ((a[i] == a[i - 1] && flag == 2) || (a[i] > a[i - 1] && flag > 0)) {
            cout << "NO" << endl;
            return 0;
        }
        if (a[i] == a[i - 1]) flag = max(flag, 1);
        if (a[i] < a[i - 1]) flag = max(flag, 2);
    }
    cout << "YES" << endl;
    return 0;
}