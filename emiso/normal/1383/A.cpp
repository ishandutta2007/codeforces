#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, t;
char a[MN], b[MN]; string sa, sb;

struct union_find {
    vector<int> parent, rank_;

    union_find(int n) {
        init(n);
    }

    void init(int n) {
        parent.resize(n + 1); rank_.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            rank_[i] = 1;
        }
    }

    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    bool join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;

        if(rank_[a] > rank_[b]) {
            parent[b] = a;
            rank_[a] += rank_[b];
        } else {
            parent[a] = b;
            rank_[b] += rank_[a];
        }
        return true;
    }
};

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %s %s", &n, a, b);
    sa = a; sb = b;

    union_find dsu(35);

    int flag = 1, ans = 0;
    for(int i = 0; i < n && flag; i++) {
        if(sa[i] > sb[i]) flag = 0;
        else if(sa[i] < sb[i])
            if(dsu.join(sa[i]-'a', sb[i]-'a'))
                ans++;
    }

    if(!flag) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }

    if(--t) goto st;
    return 0;
}