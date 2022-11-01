// January 4, 2019
// https://codeforces.com/contest/1097/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug_output.txt", "w", stderr);
#endif


    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << N); i++) {
        int cur = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) cur += a[j];
            else cur -= a[j];
        }
        if (cur % 360 == 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";


    return 0;
}