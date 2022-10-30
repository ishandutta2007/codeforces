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

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 1e6 + 100;

char s[N];
int p[N], c[N], last[N];
int pn[N], cn[N];
int n, balance[N], mnl[N], mnr[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < n; i++) {
        last[s[i] - 'a' + 1]++;
    }
    for (int i = 2; i <= 26; i++) {
        last[i] += last[i - 1];
    }
    for (int i = 0; i < n; i++) {
        c[i] = last[s[i] - 'a'];
    }
    for (int i = 0; i < n; i++) {
        p[last[s[i] - 'a']++] = i;
    }

    for (int l = 1; l < n; l <<= 1) {
        for (int i = 0; i < n; i++) {
            last[i] = i;
        }
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - l;
            if (pn[i] < 0) {
                pn[i] += n;
            }
        }
        for (int i = 0; i < n; i++) {
            p[last[c[pn[i]]]++] = pn[i];
        }
        cn[p[0]] = 0;
        int nlast = 0;
        for (int i = 1; i < n; i++) {
            int mid1 = (p[i] + l) % n, mid2 = (p[i - 1] + l) % n;
            if (c[p[i]] > c[p[i - 1]] || c[mid1] > c[mid2]) {
                nlast = i;
            }
            cn[p[i]] = nlast;
        }
        memcpy(c, cn, n * sizeof(n));
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = p[i]; j < p[i] + n; j++) {
//            putchar(s[j % n]);
//        }
//        printf("\n");
//    }

    mnl[0] = INF;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            balance[i + 1] = balance[i] + 1;
        } else {
            balance[i + 1] = balance[i] - 1;
        }
        mnl[i + 1] = min(balance[i + 1], mnl[i]);
    }
    mnr[n - 1] = balance[n];
    for (int i = n - 2; i >= 0; i--) {
        mnr[i] = min(mnr[i + 1], balance[i + 1]);
    }

    int ans = INF, ansi = 0, good = min(0, balance[n]);

    for (int i = 0; i < n; i++) {
        if (mnl[i] + balance[n] - balance[i] >= good && mnr[i] - balance[i] >= good) {
            if (ans > c[i]) {
                ans = c[i];
                ansi = i;
            }
        }
    }

    for (int i = 0; i < -balance[n]; i++) {
        putchar('(');
    }
    for (int i = ansi; i < ansi + n; i++) {
        putchar(s[i % n]);
    }
    for (int i = 0; i < balance[n]; i++) {
        putchar(')');
    }
    return 0;
}