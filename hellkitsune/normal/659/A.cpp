#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b;

int main() {
    cin >> n >> a >> b;
    --a;
    a += b;
    a %= n;
    if (a < 0) a += n;
    ++a;
    cout << a << endl;
    return 0;
}