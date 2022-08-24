#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){

    int n = nxt();
    int k = nxt();
    vector<pair<int, int>> u(n), l(n);
    for (int i = 0; i < n; i++){
        int x1 = nxt(), y1 = nxt();
        int x2 = nxt(), y2 = nxt();
        int x = x1 + x2;
        int y = y1 + y2;
        l[i] = {x, i};
        u[i] = {y, i};
    }
    sort(all(l));
    sort(all(u));
    long long ans = LLONG_MAX;
    int lu[k + 1][k + 1], ld[k + 1][k + 1], ru[k + 1][k + 1], rd[k + 1][k + 1];
    for (int i = 0; i <= k; i++){
        for (int j = 0; j <= k; j++){
            lu[i][j] = ld[i][j] = ru[i][j] = rd[i][j] = 0;
            for (int i1 = 0; i1 < i; i1++){
                for (int j1 = 0; j1 < j; j1++){
                    if (l[i1].second == u[j1].second)
                        lu[i][j]++;
                    if (l[i1].second == u[n - 1 - j1].second)
                        ld[i][j]++;
                    if (l[n - 1 - i1].second == u[j1].second)
                        ru[i][j]++;
                    if (l[n - 1 - i1].second == u[n - 1 - j1].second)
                        rd[i][j]++;
                }
            }
        }
    }

    // for (int i = 0; i <= k; i++){
    //  for (int j = 0; j <= k; j++){
    //      cerr << lu[i][j] << " ";
    //  }
    //  cerr << "\n";
    // }

    for (int i = 0; i <= k; i++){
        for (int j = 0; i + j <= k; j++){
            for (int i1 = 0; i1 <= k && i1 + i + j - lu[i][i1] - ld[j][i1] <= k; i1++){
                for (int j1 = 0; i1 + j1 <= k && j1 + i + j + i1 - lu[i][i1] - ld[j][i1] - ru[i][j1] - rd[j][j1] <= k; j1++){
                    // cerr << i << " " << j << " " << i1 << " " << j1 << "\n";
                    ans = min(ans, 1ll * max(2, (l[n - 1 - j1].first - l[i1].first + (l[n - 1 - j1].first - l[i1].first) % 2)) * max(2, (u[n - 1 - j].first - u[i].first + (u[n - 1 - j].first - u[i].first) % 2)));
                }
            }
        }
    }

    cout << ans / 4 << "\n";

    return 0;
}