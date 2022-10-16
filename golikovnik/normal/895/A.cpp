#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> pref(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt +=  x;
        pref[i] = cnt;
    }
    int cur_best = 360;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int first = pref[j] - (i > 0 ? pref[i-1] : 0);
            int second = 360 - first;
            int delta = abs(second - first);
            if (delta < cur_best) cur_best = delta;
        }
    }
    cout << cur_best;
    return 0;
}