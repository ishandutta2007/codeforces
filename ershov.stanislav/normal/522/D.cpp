#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;

using namespace std;

const int N = 550000;

int n, m, a[N], fenv[N], ans[N], prv[N];
pair<int, pair<int, int> > q[N];

int get(int i) {
    int ans = INF;
    for (; i > 0; i -= (i & (-i)) ) {
        ans = min(ans, fenv[i]);
    }
    return ans;
}

void upd(int i, int val) {
    if (i == 0) {
        return;
    }
    for (; i < N; i += (i & (-i)) ) {
        fenv[i] = min(fenv[i], val);
    }
}

int main() {
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) {
        fenv[i] = INF;
    }
    map<int, int> lst;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        prv[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &q[i].sc.fs, &q[i].fs);
        q[i].sc.sc = i;
    }
    sort(q, q + m);
    for (int i = 0, t = 1; i < m; i++) {
        while (t <= q[i].fs) {
//            cout << "t: " << t << ' ' << prv[t] << endl;
            upd(n + 1 - prv[t], t - prv[t]);
            t++;
        }
//        cout << q[i].fs << ' ' << q[i].sc.fs << endl;
        ans[q[i].sc.sc] = get(n + 1 - q[i].sc.fs);
    }
    for (int i = 0; i < m; i++) {
        if (ans[i] < INF) {
            printf("%d\n", ans[i]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}