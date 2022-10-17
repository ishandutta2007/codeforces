#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector< pair<int,int> > a(n);
    for (int i = 0; i < n; i++) {
        a[i].second = i+1;
        cin >> a[i].first;
    }
    sort(a.begin(), a.end());

    vector< pair<int,int> > ops;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (a[j].second > a[j+1].second) {
                ops.push_back({a[j+1].second, a[j].second});
                swap(a[j].second, a[j+1].second);
            }
        }
    }

    cout << ops.size() << '\n';
    for (auto x : ops) cout << x.first << ' ' << x.second << '\n';
    return 0;
}