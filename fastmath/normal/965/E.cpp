#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <random>
#include <time.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int K = 26;

string a[MAXN];

struct Node {
    bool term;
    multiset <int> ans;
    Node *son[K];
};

Node *init() {
    Node *t = new Node;
    t->term = false;
    t->ans = {};
    for (int i = 0; i < K; ++i) t->son[i] = NULL;
    return t;
}

Node *root = init();

void AddString(string s) {
    Node *curr = root;
    for (char c : s) {
        if (!curr->son[c - 'a']) curr->son[c - 'a'] = init();
        curr = curr->son[c - 'a'];        
    }
    curr->term = true;
}

void jfs(Node *t, int h) {
    int mx = -1;

    for (int i = 0; i < K; ++i) {
        if (t->son[i]) {
            jfs(t->son[i], h + 1);
            if (mx == -1 || (t->son[mx]->ans).size() < (t->son[i]->ans).size()) mx = i;
        }
    }

    if (mx != -1) swap(t->ans, t->son[mx]->ans);
    
    for (int i = 0; i < K; ++i) {
        if (t->son[i] && i != mx) {
            for (int elem : t->son[i]->ans) t->ans.insert(elem);
        }
    }
    
    if (!t->term) t->ans.erase(t->ans.find(*t->ans.rbegin()));
    t->ans.insert(h);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) AddString(a[i]);                                 

    int ans = 0;
    for (int i = 0; i < K; ++i) {
        if (root->son[i]) {
            jfs(root->son[i], 1);
            for (int elem : root->son[i]->ans) {
                ans += elem;
            }
        }   
    }

    cout << ans << '\n';
    return 0;
}