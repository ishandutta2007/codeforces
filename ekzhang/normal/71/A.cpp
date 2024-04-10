#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string w;
        cin >> w;
        if (w.size() > 10) {
            w = w[0] + to_string(w.size() - 2) + w[w.size() - 1];
        }
        cout << w << '\n';
    }

    cout.flush();
    return 0;
}