#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <cmath>
#include <random>
#include <time.h>

using namespace std;

const int K = 26;

struct Node {
    int h;
    char c;
    bool term;
    int num;
    Node *parent;
    Node *sufflink;
    Node *termlink;
    Node *son[K], *go[K];
};

Node *init(int h, char c, Node *parent) {
    Node *t = new Node;
    t->h = h;
    t->c = c;
    t->term = false;
    t->num = -1;
    t->parent = parent;
    t->sufflink = NULL;
    t->termlink = NULL;
    for (int i = 0; i < K; ++i) t->son[i] = NULL;
    for (int i = 0; i < K; ++i) t->go[i] = NULL;
    return t;   
}

Node *root;

Node *getSuffLink(Node *v);

Node *getLink(Node *v, char c) {
    if (v->go[c - 'a'] == NULL) {
        if (v->son[c - 'a']) {
            v->go[c - 'a'] = v->son[c - 'a'];
        }
        else if (v->h == 0) {
            v->go[c - 'a'] = root;
        }
        else {
            v->go[c - 'a'] = getLink(getSuffLink(v), c);
        }  
    }
    return v->go[c - 'a'];
}

Node* getSuffLink(Node *t) {
    if (!t->sufflink) {
        if (t->h <= 1) {
            t->sufflink = root;
        }
        else {
            t->sufflink = getLink(getSuffLink(t->parent), t->c);
        }
    }

    return t->sufflink;
}

Node *getTermLink(Node *t) {
    if (!t->termlink) {
        if (t->h <= 1) {
            t->termlink = root;
        }
        else if (getSuffLink(t)->term) {
            t->termlink = getSuffLink(t);
        }
        else {
            t->termlink = getTermLink(getSuffLink(t));
        }
    }
    
    return t->termlink;
}

void AddString(string s, int num) {
    Node *curr = root;
    for (char c : s) {
        if (!curr->son[c - 'a']) curr->son[c - 'a'] = init(curr->h + 1, c, curr);
        curr = curr->son[c - 'a'];
    }
    curr->term = true;
    curr->num = num;
}

const int MAXN = 1e5 + 7;

string a[MAXN];
int want[MAXN];
vector <int> p[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) cin >> want[i] >> a[i];

    root = init(0, 0, NULL);
    for (int i = 0; i < q; ++i) AddString(a[i], i);

    Node *curr = root;
    for (int i = 0; i < (int)s.size(); ++i) {
        curr = getLink(curr, s[i]);
        if (curr->term) p[curr->num].push_back(i);

        Node *t = getTermLink(curr);
        while (t->h) {
            p[t->num].push_back(i);
            t = getTermLink(t);
        }
    }                                                        
    
    for (int i = 0; i < q; ++i) {
        if ((int)p[i].size() < want[i]) {
            cout << "-1\n";
            continue;
        }
        int ans = MAXN;
        for (int j = 0; j + want[i] - 1 < (int)p[i].size(); ++j) {
            int l = p[i][j] - (int)a[i].size() + 1;
            int r = p[i][j + want[i] - 1];
            ans = min(ans, r - l + 1);
        }
        cout << ans << '\n';
    }

    return 0;
}