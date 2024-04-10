# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

string shift(string &s, int l, int r, int k) {
    rotate(s.begin() + l, s.begin() + (r - k) + 1, s.begin() + r + 1);
    return s;
}

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        --l, --r;
        k %= (r - l + 1);
        shift(s, l, r, k);
    }
    cout << s << endl;
}