# include <set>
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> p(n);
    vector <int> comp(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector <int> used(n);
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        used[i] = true;
        int cnt = 1;
        for (int j = p[i]; !used[j]; j = p[j]) {
            ++cnt;
            used[j] = true;
        }
        comp.push_back(cnt);
    }
    sort(comp.begin(), comp.end());
    if (comp.size() > 1) {
        int t = comp.back();
        comp.pop_back();
        comp.back() += t;
    }
    long long ans = 0;
    for (auto &elem : comp) ans += 1LL * elem * elem;
    cout << ans << endl;
}