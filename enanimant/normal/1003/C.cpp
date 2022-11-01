#include <bits/stdc++.h>

using namespace std;


const int MAXN = 5000;

int N, K;
int a[MAXN];
int psa[MAXN + 1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    psa[0] = 0;
    for (int i = 1; i <= N; i++) {
        psa[i] = psa[i - 1] + a[i - 1];
    }

    double ans = 0;
    for (int i = 1; i + K - 1 <= N; i++) {
        for (int j = i + K - 1; j <= N; j++) {
            ans = max(ans, (double) (psa[j] - psa[i - 1]) / (j - i + 1));
        }
    }

    cout.precision(10);
    cout << fixed;

    cout << ans << '\n';



    return 0;
}