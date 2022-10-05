#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int have[10] = {};
string a, b;
int n, m;


bool check(int len, string &t) {
    vector <int> h(10);
    string tmp;
    for (int i = 0; i < 10; ++i) h[i] = have[i];
    for (int i = 0; i < len; ++i) {
        int c = b[i] - '0';
        if (!h[c]) {
            return false;
        }
        --h[c];
        tmp += '0' + c;
    }
    if (len != m) {
        int d = b[len] - '0';
        if (d == 0 || (len == 0 && d == 1)) return false;
        for (int j = d - 1; j >= 0; --j) {
            if (h[j]) {
                --h[j];
                tmp += '0' + j;
                break;
            }
            if (j == 0) {
                return false;
            }
        }
    }
    for (int i = len + 1; i < m; ++i) {
        for (int j = 9; j >= 0; --j) {
            if (h[j]) {
                tmp += '0' + j;
                --h[j];
                break;
            }
        }
    }
    t = tmp;
    return true;
}

int main() {
    cin >> a >> b;
    for (auto c : a) {
        ++have[c - '0'];
    }
    n = a.size();
    m = b.size();
    string ans = "";
    if (n < m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 9; j >= 0; --j) {
                if (have[j]) {
                    --have[j];
                    ans += '0' + j;
                    break;
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    else {
        for (int len = 0; len <= m; ++len) {
            string tmp;
            if (check(len, tmp)) ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}
//