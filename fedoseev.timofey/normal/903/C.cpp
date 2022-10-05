#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map <int, int> cnt;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
        ans = max(ans, cnt[x]);
    }
    cout << ans << endl;
}