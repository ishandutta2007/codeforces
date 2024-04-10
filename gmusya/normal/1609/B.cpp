#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, q;
string s;

int chk(int i) {
    if (i < 0 || i + 2 >= n) {
        return 0;
    }
    return (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i + 2 < n; ++i) {
        cnt += chk(i);
    }
    while (q--) {
        int pos;
        char ch;
        cin >> pos >> ch;
        --pos;
        for (int i = pos - 2; i <= pos; ++i) {
            cnt -= chk(i);
        }
        s[pos] = ch;
        for (int i = pos - 2; i <= pos; ++i) {
            cnt += chk(i);
        }
        cout << cnt << '\n';
    }
    return 0;
}