#include <iostream>
#include <algorithm>
using namespace std;

const int kSIZE = 1e5 + 5;

string s, t;

bool fs[kSIZE], ft[kSIZE];
int real_f1[2 * kSIZE], real_f2[2 * kSIZE];
int *f1 = &real_f1[kSIZE], *f2 = &real_f2[kSIZE];

void init() {
    fill(fs, fs + kSIZE, true);
    for (int i = 0; i <= s.size() - t.size(); ++i)
        for (int j = 0; j < t.size(); ++j)
            if (s[i + j] != '?' && s[i + j] != t[j])
                fs[i] = false;
    fill(ft, ft + kSIZE, true);
    for (int i = t.size(); i > 0; --i)
        for (int j = i; j < t.size(); ++j)
            if (t[j - i] != t[j])
                ft[i] = false;
}

int main() {
    cin >> s >> t;
    if (t.size() > s.size()) {
        cout << 0;
        return 0;
    }
    init();
    fill(f1 - kSIZE, f1 + kSIZE, 0);
    fill(f2 - kSIZE, f2 + kSIZE, 0);
    for (int i = 0; i <= s.size() - t.size(); ++i) {
        if (fs[i]) {
            f1[i] = f2[i - t.size()] + 1;
            for (int j = t.size() - 1; j > 0; --j)
                if (ft[j])
                    f1[i] = max(f1[i], f1[i - j] + 1);
        }
        f2[i] = max(f2[i - 1], f1[i]);
    }
    cout << f2[s.size() - t.size()];
    return 0;
}