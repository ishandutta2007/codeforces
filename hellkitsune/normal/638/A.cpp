#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a;

int main() {
    scanf("%d%d", &n, &a);
    if (a % 2 == 1) {
        cout << (a + 1) / 2 << endl;
    } else {
        cout << n / 2 + 1 - a / 2 << endl;
    }
    return 0;
}