#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 305;
int n;
char c[N][N], d[N][N];

int solve(int x) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            d[i][j] = c[i][j];
            if ((i+j)%3 == x && c[i][j] == 'X')
                d[i][j] = 'O', ans++;
        }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n+2; i++)
            for (int j = 0; j < n+2; j++)
                c[i][j] = '.';
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> c[i][j];
        int a = solve(0), b = solve(1), e = solve(2);
        if (a <= b && a <= e)
            solve(0);
        else if (b <= e && b <= a)
            solve(1);
        else
            solve(2);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << d[i][j];
            cout << "\n";
        }
    }
}