#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

string a, b, c;
int cnt[26], cntb[26], cntc[26];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    cin >> a >> b >> c;
    for (int i = 0; i < (int) a.length(); i++) {
        cnt[a[i] - 'a']++;
    }
    for (int i = 0; i < (int) b.length(); i++) {
        cntb[b[i] - 'a']++;
    }
    for (int i = 0; i < (int) c.length(); i++) {
        cntc[c[i] - 'a']++;
    }

    int ans = 0;
    while (true) {
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] < cntb[i]) {
                flag = false;
            }
        }
        if (flag) {
            for (int i = 0; i < 26; i++) {
                cnt[i] -= cntb[i];
            }
            ans++;
        } else {
            break;
        }
    }
    int res = ans;
    int ans_b = ans, ans_c = 0;
    int cur_b = ans, cur_c = 0;
    while (true) {
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] < cntc[i]) {
                flag = false;
            }
        }
        if (flag) {
            for (int i = 0; i < 26; i++) {
                cnt[i] -= cntc[i];
            }
            ans++;
            cur_c++;
        } else {
            break;
        }
    }
        if (res < ans) {
            ans_b = cur_b;
            ans_c = cur_c;
            res = ans;
        }
    for (; cur_b > 0; ) {
        for (int i = 0; i < 26; i++) {
            cnt[i] += cntb[i];
        }
        ans--;
        cur_b--;
        while (true) {
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] < cntc[i]) {
                    flag = false;
                }
            }
            if (flag) {
                for (int i = 0; i < 26; i++) {
                    cnt[i] -= cntc[i];
                }
                ans++;
                cur_c++;
            } else {
                break;
            }
        }
        if (res < ans) {
            ans_b = cur_b;
            ans_c = cur_c;
            res = ans;
        }
    }
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < (int) a.length(); i++) {
        cnt[a[i] - 'a']++;
    }

    for (int i = 0; i < ans_b; i++) {
        cout << b;
        for (int i = 0; i < 26; i++) {
            cnt[i] -= cntb[i];
        }
    }
    for (int i = 0; i < ans_c; i++) {
        cout << c;
        for (int i = 0; i < 26; i++) {
            cnt[i] -= cntc[i];
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            printf("%c", 'a' + i);
        }
    }

    return 0;
}