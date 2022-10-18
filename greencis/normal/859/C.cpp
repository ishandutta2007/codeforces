#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[55];
int x[55][55], y[55][55];
char u[55][55];

pii solve(int L, int R) { ///  ALICE/BOB
    if (L > R)
        return {0, 0};
    if (!u[L][R]) {
        u[L][R] = 1;
        if (L == R) {
            x[L][R] = 0;
            y[L][R] = a[L];
        } else {
            int cursum = 0;
            int bob = 0, alice = 1e9;
            for (int i = L; i <= R; ++i) {
                pii qqq = solve(i + 1, R); /// bob/alice
                int curbob = qqq.first + a[i];
                int curalice = qqq.second + cursum;
                if (curbob > bob || (curbob == bob && curalice < alice))
                    bob = curbob, alice = curalice;
                cursum += a[i];
            }
            x[L][R] = alice;
            y[L][R] = bob;
        }
    }
    return {x[L][R], y[L][R]};
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    pii qqq = solve(0, n - 1);
    cout << qqq.first << " " << qqq.second << endl;

    return 0;
}