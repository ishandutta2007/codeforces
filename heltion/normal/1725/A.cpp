#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL N, M;
    cin >> N >> M;
    if (M > 1) cout << N * (M - 1);
    else cout << N - 1;
}