#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;
string t[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

int main() {
    cin >> s;
    int n = (int)s.size();
    int cnt = 0;
    forn(i, s.size()) {
        forn(j, 5) if (i + (int)t[j].size() <= n) {
            if (s.substr(i, t[j].size()) == t[j]) {
                ++cnt;
            }
        }
    }
    if (cnt == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}