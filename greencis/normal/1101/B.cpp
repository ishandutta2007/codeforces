#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

void fail() { cout << -1; exit(0); }

char s[500005];
int n;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> (s + 1);
    n = strlen(s + 1);
    int i = 1;
    for (; i <= n && s[i] != '['; ++i); if (i > n) fail();
    for (; i <= n && s[i] != ':'; ++i); if (i > n) fail();

    int j = n;
    for (; j >= 1 && s[j] != ']'; --j); if (j < 1) fail();
    for (; j >= 1 && s[j] != ':'; --j); if (j < 1) fail();
    if (i >= j) fail();
    int cnt = 0;
    for (; i < j; ++i) cnt += (s[i] == '|');
    cout << cnt + 4;
}