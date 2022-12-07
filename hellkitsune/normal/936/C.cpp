#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[2005], t[2005], tmp[2005];
int bal[26];
vector<int> ans;
int done = 0;

void makeShift(int cnt) {
    ans.pb(cnt);
    int ind = 0;
    forn(i, cnt) {
        tmp[ind++] = s[n - 1 - i];
    }
    forn(i, n - cnt) {
        tmp[ind++] = s[i];
    }
    forn(i, n) s[i] = tmp[i];
}

void step(char c) {
//    cerr << s << endl;
    int pos = done;
    while (pos < n && s[pos] != c) {
        ++pos;
    }
    assert(pos < n);
    int need = n - 1 - pos;
    if (need > 0) {
        makeShift(need);
    }
    if (n - done - need > 0) {
        makeShift(n - done - need);
    }
    if (done > 0) {
        makeShift(done);
    }
    ++done;
}

int main() {
    scanf("%d%s%s", &n, s, t);
    forn(i, n) ++bal[s[i] - 'a'];
    forn(i, n) --bal[t[i] - 'a'];
    forn(i, 26) if (bal[i] != 0) {
        cout << -1 << endl;
        return 0;
    }
    int l = n / 2 - 1;
    int r = l + 1;
    int cur = n % 2;
    forn(i, n) {
        if (cur == 0) {
            step(t[l]);
            --l;
        } else {
            step(t[r]);
            ++r;
        }
        cur ^= 1;
    }
    forn(i, n) assert(s[i] == t[i]);
    printf("%d\n", (int)ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    puts("");
    return 0;
}