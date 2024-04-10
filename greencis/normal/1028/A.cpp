#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

char s[205][205];
ll sumx, sumy;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == 'B') {
                sumx += j;
                sumy += i;
                ++cnt;
            }
        }
    }
    cout << sumy / cnt << " " << sumx / cnt;
}