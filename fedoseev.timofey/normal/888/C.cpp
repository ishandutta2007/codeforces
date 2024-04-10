#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector <int> max_dist(26, 0);
    vector <int> last(26, -1);
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        max_dist[s[i] - 'a'] = max(max_dist[s[i] - 'a'], i - last[s[i] - 'a']);
        last[s[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; ++i) {
        max_dist[i] = max(max_dist[i], n - last[i]);
    }
    int ans = 1e9;
    for (int i = 0; i < 26; ++i) {
        ans = min(ans, max_dist[i]);
    }
    cout << ans << endl;
}