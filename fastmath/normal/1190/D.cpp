#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ls order_of_key

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int N = 2e5 + 7;
struct Point {
    int x, y;
};  
Point a[N];
vector <int> d[N];

int f(int n) {
    return n * (n + 1) / 2;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> cx, cy;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        cx.push_back(a[i].x); 
        cy.push_back(a[i].y);
    }
    sort(cx.begin(), cx.end()); cx.resize(unique(cx.begin(), cx.end()) - cx.begin());
    sort(cy.begin(), cy.end()); cy.resize(unique(cy.begin(), cy.end()) - cy.begin());
    for (int i = 0; i < n; ++i) {
        a[i].x = lower_bound(cx.begin(), cx.end(), a[i].x) - cx.begin();
        a[i].y = lower_bound(cy.begin(), cy.end(), a[i].y) - cy.begin();
        d[a[i].y].push_back(a[i].x);
    }   
    int ans = 0;
    ordered_set ms;
    for (int i = N - 1; i >= 0; --i) {
        if (d[i].empty()) continue;
        sort(d[i].begin(), d[i].end());
        ans -= f(ms.ls(d[i][0]));
        for (int j = 0; j + 1 < (int)d[i].size(); ++j) {
            ans -= f(ms.ls(d[i][j + 1]) - ms.ls(d[i][j] + 1));
        }       
        ans -= f(ms.size() - ms.ls(d[i].back() + 1));
        for (int e : d[i]) ms.insert(e);
        ans += f(ms.size());
    }   
    cout << ans << '\n';
}