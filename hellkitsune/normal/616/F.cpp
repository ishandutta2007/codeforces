#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 611111;
int ord[MX], c[MX], nord[MX], nc[MX];
int cnt[MX];

void saLcp(basic_string<int> s, int n) {
    ++n;
    REP(i, MX) cnt[i] = 0;
    cnt[0] = 1;
    REP(i, n - 1) ++cnt[s[i]];
    REP(i, MX - 1) cnt[i + 1] += cnt[i];
    REP(i, n - 1) ord[--cnt[s[i]]] = i;
    ord[0] = n - 1;
    c[ord[0]] = 0;
    int cpos = 0;
    for (int i = 1; i < n; ++i) {
        if (s[ord[i - 1]] != s[ord[i]]) ++cpos;
        c[ord[i]] = cpos;
    }
    for (int sz = 1; sz < n; sz <<= 1) {
        REP(i, n) {
            nord[i] = ord[i] - sz;
            if (nord[i] < 0) nord[i] += n;
        }
        REP(i, n) cnt[i] = 0;
        REP(i, n) ++cnt[c[nord[i]]];
        REP(i, n - 1) cnt[i + 1] += cnt[i];
        for (int i = n - 1; i >= 0; --i)
            ord[--cnt[c[nord[i]]]] = nord[i];
        nc[ord[0]] = 0;
        cpos = 0;
        for (int i = 1; i < n; ++i) {
            int mid1 = ord[i - 1] + sz, mid2 = ord[i] + sz;
            if (mid1 >= n) mid1 -= n;
            if (mid2 >= n) mid2 -= n;
            if (c[ord[i - 1]] != c[ord[i]] || c[mid1] != c[mid2]) ++cpos;
            nc[ord[i]] = cpos;
        }
        REP(i, n) c[i] = nc[i];
    }
    REP(i, n) c[ord[i]] = i;
    for (int i = 0, j, k = 0; i < n; cnt[c[i++]] = k) {
        if (c[i] > 0) for (k ? k-- : 0, j = ord[c[i] - 1]; s[i + k] == s[j + k]; k++);
        else k = 0;
    }
    --n;
    REP(i, n) ord[i] = ord[i + 1];
    REP(i, n) cnt[i] = cnt[i + 1];
}

int n;
int a[100005];
string s[100005];
char buf[500005];
int len[MX];
int mul[MX];
LL sum[MX];
int le[MX], ri[MX];
basic_string<int> ss;
int tmp[MX];

int sz;
void re(int *a) {
    REP(i, sz) tmp[i] = a[ord[i]];
    REP(i, sz) a[i] = tmp[i];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", buf);
        s[i] = string(buf);
    }
    REP(i, n) scanf("%d", a + i);
    int pos = 0;
    REP(i, n) {
        int rem = (int)s[i].length();
        for (char c : s[i]) {
            ss += c - 'a' + 1;
            len[pos] = rem--;
            mul[pos++] = a[i];
        }
        ss += 30 + i;
        len[pos] = 0;
        mul[pos++] = 0;
    }
    sz = (int)ss.size();
    saLcp(ss, sz);
    re(mul);
    re(len);
    cnt[sz] = 0;
    LL ans = 0;
    REP(i, sz) if (cnt[i] != len[i] && cnt[i + 1] != len[i]) {
        ans = max(ans, (LL)len[i] * mul[i]);
    }
    for (int i = 1; i < sz; ++i) {
        le[i] = i;
        while (le[i] > 1 && cnt[le[i] - 1] >= cnt[i]) le[i] = le[le[i] - 1];
    }
    for (int i = sz - 1; i >= 1; --i) {
        ri[i] = i;
        while (ri[i] < sz - 1 && cnt[ri[i] + 1] >= cnt[i]) ri[i] = ri[ri[i] + 1];
    }
    sum[0] = 0;
    REP(i, sz) sum[i + 1] = sum[i] + mul[i];
    for (int i = 1; i < sz; ++i) {
        ans = max(ans, (LL)cnt[i] * (sum[ri[i] + 1] - sum[le[i] - 1]));
    }
    cout << ans << endl;
    return 0;
}