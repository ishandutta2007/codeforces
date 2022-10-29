#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>

#define forn(i, a, b) for (int i = (a); i < (b); i++)
#define ford(i, a, b) for (int i = (a); i >= (b); i--)
#define min(a, b) ((a < b) ? (a) : (b))
#define abs(a) ((a < 0) ? (-(a)) : (a))
#define max(a, b) ((a > b) ? (a) : (b))

using namespace std;

const int maxlen = 1000002, maxm = 10001;

typedef unsigned long long ull;

char s[maxlen];
int m;
map<int, int> ans;
bool qq[1<<27];
int queries[maxm];

int main() {
    scanf("%s", s);
    scanf("%d", &m);
    forn(i, 0, m) {
        char q[30];
        scanf("%s", q);
        int len = strlen(q);
        int mask = 0;
        forn(j, 0, len)
            mask |= (1 << (q[j] - 'a'));
        queries[i] = mask;
        qq[mask] = 1;
    }
    int last[26];
    forn(i, 0, 26) last[i] = -1;
    int n = strlen(s);
    forn(i, 0, n) {
        if (i < n - 1 && s[i] == s[i + 1]) {
            last[s[i] - 'a'] = i;
            continue;
        }
        int from = (i == n - 1 ? -1 : last[s[i + 1] - 'a']);
        last[s[i] - 'a'] = i;
        pair<int, char> last_cop[26];
        forn(j, 0, 26)
            last_cop[j].first = last[j], last_cop[j].second = j;
        sort(last_cop, last_cop + 26);
        int current_mask = 0;
        for (int j = 25; j >= 0 && last_cop[j].first > from; j--) {
            current_mask |= (1 << (last_cop[j].second));
            if (qq[current_mask])
                ans[current_mask]++;
        }
    }
    forn(i, 0, m){
        cout << ans[queries[i]] << endl;
    }
}