#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;
int n;

map<char, int> cnt;

int main() {
    cin >> s;
    n = int(s.size());
    forn(i, n) if (s[i] != '!') {
        for (int j = i + 4; j < n; j += 4) {
            if (s[j] == '!') {
                ++cnt[s[i]];
            }
            s[j] = s[i];
        }
        for (int j = i - 4; j >= 0; j -= 4) {
            if (s[j] == '!') {
                ++cnt[s[i]];
            }
            s[j] = s[i];
        }
    }
    printf("%d %d %d %d\n", cnt['R'], cnt['B'], cnt['Y'], cnt['G']);
    return 0;
}