#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int n, q;    
string s;
struct Node {
    int lpr, rml_l, rml_r, lmr_l, lmr_r, lpr_l, lpr_r;
    int lpr_all, rml_all, lmr_all;
};  
Node tree[N << 2];
Node merge(Node l, Node r) {
    Node ans;
    ans.lpr = max(l.lpr_r + r.lmr_l, l.rml_r + r.lpr_l);       
    ans.lpr = max(ans.lpr, l.lpr);
    ans.lpr = max(ans.lpr, r.lpr);

    ans.rml_l = max(l.rml_l, l.rml_all + r.rml_l);
    ans.rml_r = max(r.rml_r, r.rml_all + l.rml_r);

    ans.lmr_l = max(l.lmr_l, l.lmr_all + r.lmr_l);
    ans.lmr_r = max(r.lmr_r, r.lmr_all + l.lmr_r);    

    ans.lpr_l = max(l.lpr_all + r.lmr_l, l.rml_all + r.lpr_l);
    ans.lpr_l = max(ans.lpr_l, l.lpr_l);

    ans.lpr_r = max(l.lpr_r + r.lmr_all, l.rml_r + r.lpr_all);
    ans.lpr_r = max(ans.lpr_r, r.lpr_r);
    
    ans.lpr_all = max(l.lpr_all + r.lmr_all, l.rml_all + r.lpr_all);

    ans.rml_all = l.rml_all + r.rml_all;
    ans.lmr_all = l.lmr_all + r.lmr_all;

    return ans;
}

Node init(char c) {
    Node ans;
    ans.lpr_all = ans.lpr = ans.lpr_l = ans.lpr_r = 1;
    if (c == '(') {
        ans.rml_l = ans.rml_r = 0;
        ans.lmr_l = ans.lmr_r = 1;
        ans.rml_all = -1;
        ans.lmr_all = 1;
    }
    else {
        ans.rml_l = ans.rml_r = 1;
        ans.lmr_l = ans.lmr_r = 0;
        ans.rml_all = 1;
        ans.lmr_all = -1;        
    }   
    return ans;
}   
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = init(s[tl]);
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm); build(v * 2 + 2, tm + 1, tr);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
void upd(int v, int tl, int tr, int p) {
    if (tl == tr) {
        if (s[tl] == '(') {
            s[tl] = ')';
        }   
        else {
            s[tl] = '(';
        }   
        tree[v] = init(s[tl]);
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) upd(v * 2 + 1, tl, tm, p);
    else upd(v * 2 + 2, tm + 1, tr, p);
    tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> q;
    cin >> s;
    build(0, 0, s.size() - 1);
    cout << tree[0].lpr << '\n';
    while (q--) {
        int i, j;
        cin >> i >> j;
        --i; --j;
        upd(0, 0, s.size() - 1, i);
        upd(0, 0, s.size() - 1, j);
        cout << tree[0].lpr << '\n';
    }   
}