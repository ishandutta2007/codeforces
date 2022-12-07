#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;
map<string, int> cnt;

int main() {
    int n;
    cin >> n;
    cin >> s;
    forn(i, n - 1) {
        string cur = s.substr(i, 2);
        ++cnt[cur];
    }
    string best = "";
    int bestCnt = 0;
    for (pair<string, int> p : cnt) {
        if (p.second > bestCnt) {
            best = p.first;
            bestCnt = p.second;
        }
    }
    cout << best << endl;
    return 0;
}