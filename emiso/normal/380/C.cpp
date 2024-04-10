#include <bits/stdc++.h>

using namespace std;

string str;
char s[1000100];

int n, ans[1000100];
vector<pair<int, int>> q[1000100];
stack<int> close;

template<typename T>
struct fenwick_tree {
    vector<T> a;

    fenwick_tree(int n) {
        a.resize(n + 1);
    }

    fenwick_tree(vector<T> &vec) {
        a = vec;
        for(int i = 1; i < a.size(); i++)
            a[i + (i & -i)] += a[i];
    }

    void update(int idx, T delta) {
        for(; idx < a.size(); idx += (idx & -idx)) a[idx] += delta;
    }

    int query(int idx) {
        T ret = 0;
        for(; idx; idx -= (idx & -idx)) ret += a[idx];
        return ret;
    }
};

int main() {
    scanf("%s %d", s, &n);
    str = s;

    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        q[a].emplace_back(b, i);
    }

    fenwick_tree<int> bit(1000100);
    for(int i = (int)str.size()-1; i >= 0; i--) {
        sort(q[i].begin(), q[i].end());
        if(str[i] == ')') close.push(i);
        else if(!close.empty()) {
            int x = close.top();
            close.pop();
            bit.update(x, 2);
        }

        for(auto p : q[i]) {
            ans[p.second] = bit.query(p.first);
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}