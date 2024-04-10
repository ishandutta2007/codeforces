#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n;

int main() {
    cin >> n;
    cout << 1 + 3 * (n - 3) + (n - 3) * (n - 4) << endl;
    return 0;
}