#include<bits/stdc++.h>

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
#define rank _rank

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 5e5 + 100;

char s[N];

vector<vector<int> > ans;
int to[N], from[N];
bool used[N];

int par[N], rk[N];

int get_par(int i) {
    if (par[i] == i) {
        return i;
    } else {
        return par[i] = get_par(par[i]);
    }
}

void un(int a, int b) {
    a = get_par(a);
    b = get_par(b);
    if (a == b) {
        return;
    }
    if (rk[a] > rk[b]) {
        swap(a, b);
    }
    if (rk[a] == rk[b]) {
        rk[b]++;
    }
    par[a] = b;
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf(" %s", s);
    int n = strlen(s);
    set<int> rs, ls;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            rs.insert(i);
        } else {
            ls.insert(i);
        }
    }

    rs.insert(1e6);
    ls.insert(1e6);

    while (rs.size() > 1 || ls.size() > 1) {
        vector<int> cur;
        int fs = INF;
        if (ls.size()) {
            fs = min(*ls.begin(), fs);
        }
        if (rs.size()) {
            fs = min(*rs.begin(), fs);
        }
        for (; fs != 1e6; ) {
            cur.pb(fs);
            int nxt = 1e6;
            if (s[fs] == 'R') {
                rs.erase(fs);
                nxt = *ls.upper_bound(fs);
            } else {
                ls.erase(fs);
                nxt = *rs.upper_bound(fs);
            }
            fs = nxt;
        }
        ans.pb(cur);
    }

//    cout << ans.size() << endl;
//    for (auto i : ans) {
//        for (auto j : i) {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }

    set<int> el, er, sl, sr;
    for (int i = 0; i < ans.size(); i++) {
        if (s[ans[i][0]] == 'L') {
            sl.insert(i);
        } else {
            sr.insert(i);
        }
        if (s[ans[i].back()] == 'L') {
            el.insert(i);
        } else {
            er.insert(i);
        }
    }
    int cnt = (int) ans.size();
    int cnt_all = cnt;
    for (int i = 0; i < cnt_all; i++) {
        to[i] = from[i] = -1;
        par[i] = i;
    }
    while (true) {
        bool flag = false;
        if (el.size() && sr.size()) {
            int a = *el.begin(), b = *sr.begin();
            if (get_par(a) == get_par(b)) {
                if (el.size() > 1) {
                    a = *el.rbegin();
                } else if (sr.size() > 1) {
                    b = *sr.rbegin();
                }
            }
            if (get_par(a) != get_par(b)) {
                to[a] = b;
                from[b] = a;
                el.erase(a);
                sr.erase(b);
                un(a, b);
                cnt--;
                flag = true;
            }
        }
        if (er.size() && sl.size()) {
            int a = *er.begin(), b = *sl.begin();
            if (get_par(a) == get_par(b)) {
                if (er.size() > 1) {
                    a = *er.rbegin();
                } else if (sl.size() > 1) {
                    b = *sl.rbegin();
                }
            }
            if (get_par(a) != get_par(b)) {
                to[a] = b;
                from[b] = a;
                un(a, b);
                er.erase(a);
                sl.erase(b);
                cnt--;
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
//    for (int i = 0; i < cnt_all; i++) {
//        cout << to[i] << ' ' << from[i] << endl;
//    }
    assert(cnt <= 2);
    int cur = 0;
    while (from[cur] != -1) {
        cur = from[cur];
    }
    vector<int> ans1, ans2;
    while (true) {
        for (auto i : ans[cur]) {
            ans1.pb(i);
        }
        used[cur] = 1;
        cur = to[cur];
        if (cur == -1) {
            break;
        }
    }
    cur = -1;
    for (int i = 0; i < cnt_all; i++) {
        if (!used[i]) {
            cur = i;
            while (from[cur] != -1) {
                cur = from[cur];
            }
            break;
        }
    }
    if (cur != -1) {
        while (true) {
            for (auto i : ans[cur]) {
                ans2.pb(i);
            }
            used[cur] = 1;
            cur = to[cur];
            if (cur == -1) {
                break;
            }
        }
        if (ans2.back() < ans1.back()) {
            swap(ans1, ans2);
        }
        ans1.pb(ans2.back());
        ans2.pop_back();
        for (auto i : ans2) {
            ans1.pb(i);
        }
    }
    int mn = 0;
    assert(ans1.size() == n);
    for (int i = 0; i < n - 1; i++) {
        if (ans1[i + 1] < ans1[i]) {
            mn++;
        }
    }
    printf("%d\n", mn);
    for (auto i : ans1) {
        printf("%d ", i + 1);
    }

    return 0;
}