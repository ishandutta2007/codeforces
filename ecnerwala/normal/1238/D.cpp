#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin >> N;
    string S; cin >> S;
    vector<int> runs;
    for (int i = 0; i < N; i++) {
        if (i == 0 || S[i] != S[i-1]) runs.push_back(0);
        runs.back()++;
    }
    long long ans = 1ll * N * (N-1) / 2;
    for (int i = 0; i+1 < int(runs.size()); i++) {
        ans -= runs[i] + runs[i+1] - 1;
    }
    cout << ans << '\n';
}