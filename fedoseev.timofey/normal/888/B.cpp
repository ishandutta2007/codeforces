#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> cnt(4);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'U') ++cnt[0];
        if (c == 'D') ++cnt[1];
        if (c == 'L') ++cnt[2];
        if (c == 'R') ++cnt[3];
    }
    cout << 2 * min(cnt[0], cnt[1]) + 2 * min(cnt[2], cnt[3]) << endl;
}