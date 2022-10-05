#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    deque <int> d;
    for (int i = 0; i < n; ++i) {
        d.push_back(v[i]);
        while (!d.empty() && d.front() <= v[i] - m) {
            d.pop_front();
        }
        while (d.size() >= k) {
            ++ans;
            d.pop_back();
        }
    }
    cout << ans << endl;
}