#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> cnt1(26);
vector <int> cnt2(26);

int main() {
    int k, n;
    cin >> k >> n;
    vector <string> s(k);
    for (int i = 0; i < k; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        ++cnt1[s[0][i] - 'a'];
    }
    int cnt = 0;
    for (int i = 0; i < 26; ++i) if (cnt1[i]) ++cnt;
    bool diff = false;
    if (cnt == n) diff = true;
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < 26; ++j) cnt2[j] = 0;
        for (int j = 0; j < n; ++j) ++cnt2[s[i][j] - 'a'];
        if (cnt2 != cnt1) {
            cout << -1 << endl;
            return 0;
        }
    }
    bool fl = true;
    for (int i = 0; i + 1 < k; ++i) {
        if (s[i] != s[i + 1]) fl = false;
    }
    if (fl) {
        swap(s[0][0], s[0][1]);
        cout << s[0] << endl;
        return 0;
    }
    vector <int> pos;
    for (int i = 1; i < k; ++i) {
        if (s[0] != s[i]) {
            for (int j = 0; j < n; ++j) {
                if (s[0][j] != s[i][j]) pos.push_back(j);
            }
            if (pos.size() > 4) {
                cout << -1 << endl;
                return 0;
            }
            break;
        }
    }
    for (auto p : pos) {
        for (int j = 0; j < n; ++j) {
            bool fl = false;
            if (p == j) continue;
            swap(s[0][p], s[0][j]);
            bool check = true;
            for (int g = 1; g < k; ++g) {
                int cnt = 0;
                for (int h = 0; h < n; ++h) {
                    if (s[0][h] != s[g][h]) ++cnt;
                }
                if (cnt != 0 && cnt != 2) check = false;
                if (cnt == 0) fl = true;
            }
            if (check && fl && !diff) {
                cout << s[0] << endl;
                return 0;
            }
            if (!fl && check) {
                cout << s[0] << endl;
                return 0;
            }
            swap(s[0][p], s[0][j]);
        }
    }
    cout << -1 << endl;
    return 0;
}