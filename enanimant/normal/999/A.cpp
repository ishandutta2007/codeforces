// July 2, 2018
// http://codeforces.com/problemset/problem/999/A


#include <bits/stdc++.h>

using namespace std;


const int MAXN = 100;


int N, K;
vector<int> a;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (a[i] <= K) ans++;
        else break;
    }

    if (ans != N) {
        for (int i = N - 1; i >= 0; i--) {
            if (a[i] <= K) ans++;
            else break;
        }
    }

    cout << ans << '\n';


    return 0;
}