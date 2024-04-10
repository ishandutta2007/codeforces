#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define f first

typedef long long ll;
typedef unsigned long long ull;

template <typename T1, typename T2> inline void chkmin(T1 &x, T2 y) { if (y < x) x = y; };
template <typename T1, typename T2> inline void chkmax(T1 &x, T2 y) { if (y > x) x = y; };

struct node {
    node *go0, *go1;
    int term, sum;
    node() {
        term = sum = 0;
        go0 = go1 = nullptr;
    }
};

string convert(int x) {
    string res = "";
    for (int i = 29; i >= 0; --i) {
        if ((x >> i) & 1) res += '1';
        else res += '0';
    }
    return res;
}

int convert_back(string s) {
    int x = 0;
    for (int i = 29; i >= 0; --i) {
        if (s[30 - i - 1] == '1') {
            x |= (1 << i);
        }
    }
    return x;
}

int tsum(node *t) {
    return (t == nullptr ? 0 : t->sum);
}

void add(node *&t, string &s, int pos, int d) {
    if (pos == (int)s.size()) {
        t->term += d;
        t->sum += d;
    } else {
        if (s[pos] == '0') {
            if (t->go0 == nullptr)
                t->go0 = new node();
            add(t->go0, s, pos + 1, d);
        } else {
            if (t->go1 == nullptr)
                t->go1 = new node();
            add(t->go1, s, pos + 1, d);
        }                            
        t->sum = t->term + tsum(t->go1) + tsum(t->go0);
    }
}

string st;
void get(node *t, string &s, int pos) {
    assert(t != nullptr);
    if (pos == (int)s.size()) {
        return;
    }

    if (s[pos] == '0' && tsum(t->go0) || (s[pos] == '1' && !tsum(t->go1))) {
        st += '0';
        if (t->go0 == nullptr)
            t->go0 = new node();
        get(t->go0, s, pos + 1);
    } else {
        st += '1';
        if (t->go1 == nullptr)
            t->go1 = new node();
        get(t->go1, s, pos + 1); 
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    node *t = new node();

    int n;
    cin >> n;
    vector <int> a(n);
    rep(i, n) cin >> a[i];
    
    rep(i, n) {
        int x;
        cin >> x;
        string s = convert(x);
        add(t, s, 0, 1);
    }

    vector <int> ans(n);
    rep(i, n) {
        st = "";
        string s = convert(a[i]);
//        cout << s << endl;
        get(t, s, 0);
//        cout << st << endl;
//        cout << endl;
        ans[i] = (convert_back(st) ^ a[i]);
        add(t, st, 0, -1);
    }

    rep(i, n) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}