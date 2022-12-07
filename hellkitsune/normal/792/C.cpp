#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;
int n;

string solve(string s) {
    int need = 0;
    for (char c : s) {
        need += c - '0';
    }
    need %= 3;
    if (need == 0) {
        return s;
    }
    vector<int> can2;
    for (int i = 1; i < (int)s.length(); ++i) {
        if (need == (s[i] - '0') % 3) {
            s.erase(i, 1);
            return s;
        } else if ((s[i] - '0') % 3 != 0 && (int)can2.size() < 2) {
            can2.pb(i);
        }
    }
    if ((int)can2.size() == 2) {
        s.erase(can2[1], 1);
        s.erase(can2[0], 1);
        return s;
    }
    return "-1";
}

string getMax(string a, string b) {
    if (a == "-1") {
        return b;
    }
    if (b == "-1") {
        return a;
    }
    if (a.length() > b.length()) {
        return a;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = (int)s.length();
    string ans = "-1";

    forn(i, n) if (s[i] == '0') {
        ans = "0";
    }
    ans = getMax(ans, solve(s));
    int ind = 0;
    forn(times, 2) {
        ++ind;
        while (ind < n && s[ind] == '0') {
            ++ind;
        }
        if (ind < n) {
            ans = getMax(ans, solve(s.substr(ind)));
        }
    }

    cout << ans << endl;
    return 0;
}