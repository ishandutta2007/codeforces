#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;

int main() {
    cin >> s;
    int len = (int)s.length();
    int ex = 0;
    REP(i, len) if (s[i] == 'e') {
        string t = s.substr(i + 1);
        istringstream iss(t);
        iss >> ex;
        s = s.substr(0, i);
        break;
    }
    int pos = -1;
    len = (int)s.length();
    REP(i, len) if (s[i] == '.') {
        pos = i;
        break;
    }
    while (ex > 0) {
        --ex;
        if (pos == len - 1) {
            s[pos] = '0';
            s.pb('.');
            ++len;
            ++pos;
        } else {
            swap(s[pos], s[pos + 1]);
            ++pos;
        }
    }
    while (ex < 0) {
        ++ex;
        if (pos == 0) {
            s = string(1, '.') + s;
            s[1] = '0';
            ++len;
        } else {
            swap(s[pos], s[pos - 1]);
            --pos;
        }
    }
    if (pos == 0) {
        s = string(1, '0') + s;
        ++len;
        ++pos;
    }
    while (s.back() == '0') {
        --len;
        s.pop_back();
    }
    if (pos == len - 1) {
        s.pop_back();
    }
    printf("%s\n", s.c_str());
    return 0;
}