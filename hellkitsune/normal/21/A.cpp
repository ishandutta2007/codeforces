#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

string s;
int atPos = -1;
bool flag = false;
string s1, s2, s3;

void checkUsername(string s) {
    for (char c : s) if (c != '_' && !(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9')) {
        cout << "NO\n";
        exit(0);
    }
}

int main() {
    getline(cin, s);
    REP(i, s.length()) {
        if (s[i] == '@') {
            if (atPos == -1) {
                atPos = i;
                s1 = s.substr(0, i);
                s2 = s.substr(i + 1);
            } else {
                cout << "NO\n";
                return 0;
            }
        } else if (s[i] == '/') {
            if (atPos == -1 || flag) {
                cout << "NO\n";
                return 0;
            }
            flag = true;
            s2 = s.substr(atPos + 1, i - atPos - 1);
            s3 = s.substr(i + 1);
        }
    }
    if ((int)s1.length() < 1 || (int)s1.length() > 16) {
        cout << "NO\n";
        return 0;
    }
    checkUsername(s1);
    if (flag && ((int)s3.length() < 1 || (int)s3.length() > 16)) {
        cout << "NO\n";
        return 0;
    }
    if (flag) checkUsername(s3);
    if ((int)s2.length() < 1 || (int)s2.length() > 32) {
        cout << "NO\n";
        return 0;
    }
    int pos = -1;
    int wordCount = 0;
    REP(i, (int)s2.length() + 1) {
        if (i == (int)s2.length() || s2[i] == '.') {
            if (i - pos == 1 || i - pos > 17) {
                cout << "NO\n";
                return 0;
            }
            checkUsername(s2.substr(pos + 1, i - pos - 1));
            ++wordCount;
            pos = i;
        }
    }
    cout << "YES\n";
    return 0;
}