#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int LG = 20;

struct Node {
    Node *l, *r;
};

Node *init() {
    Node *t = new Node;
    t->l = t->r = NULL;
    return t;
}

vector <int> d[MAXN];
Node *a[MAXN];

void add1(int num, int x) {
    Node *curr = a[num];
    for (int i = LG - 1; i >= 0; --i) {
        if (!((x >> i) & 1)) {
            if (!curr->l) curr->l = init();
            curr = curr->l;
        }
        else {
            if (!curr->r) curr->r = init();
            curr = curr->r;
        }
    }
}

void add(int x) {
    for (int i : d[x]) {
        add1(i, x);
    }
}

int get1(int num, int x, int mx, int pr) {
    Node *curr = a[num];
    int val = 0;
    for (int i = LG - 1; i >= LG - pr; --i) {
        if (!((mx >> i) & 1)) {
            if (!curr->l) return -1;
            curr = curr->l;
        }
        else {
            if (!curr->r) return -1;
            curr = curr->r;
            val += (1 << i);
        }
    }
    
    if (pr == LG) return val;

    int bt = LG - pr - 1;
    if ((mx >> bt) & 1) {
        if (curr->l) curr = curr->l;
        else return -1;
    }
    else {
        return -1;
    }
    
    for (int i = LG - pr - 2; i >= 0; --i) {
        if (!((x >> i) & 1)) {
            if (curr->r) {
                curr = curr->r;
                val += (1 << i);
            }
            else {
                if (curr->l) curr = curr->l;
                else return -1;
            }
        }
        else {
            if (curr->l) curr = curr->l;
            else {
                if (curr->r) {
                    curr = curr->r;
                    val += (1 << i);
                }
                else return -1;
            }
        }
    }

    return val;
}

int get(int x, int k, int mx) {
    int res = -1;
    for (int pr = 0; pr <= LG; ++pr) {
        int newres = get1(k, x, mx, pr);
        if (newres == -1) continue;
        if (res == -1 || (res ^ x) < (newres ^ x)) res = newres;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) d[j].push_back(i);
    }

    for (int i = 0; i < MAXN; ++i) a[i] = init();

    set <int> ms;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;
            if (ms.find(x) != ms.end()) continue;
            ms.insert(x);
            add(x);
        }
        else {
            int x, k, s;
            cin >> x >> k >> s;
            if (x % k) {
                cout << "-1\n";
            }
            else if (s - x < 0) {
                cout << "-1\n";
            }
            else {
                cout << get(x, k, s - x) << '\n';
            }
        }
    }
    
    return 0;
}