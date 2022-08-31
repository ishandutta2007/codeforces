#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){

    int n = nxt();
    vector<vector<int> > a(n);
    vector<int> cnt(n);
    vector<char> turn(n);
    for (itn i = 0; i < n - 1; i++){
        int x = nxt() - 1;
        int y = nxt() - 1;
        a[x].pb(y);
        a[y].pb(x);
    }
    if (n <= 2){
        puts("1 1");
        return 0;
    }
    vector<char> used(n);
    vector<int> st(1, 0);
    vector<int> order;
    vector<int> p(n);
    p[0] = -1;
    turn[0] = 0;
    while (!st.empty()){
        itn v = st.back();
        order.push_back(v);
        st.pop_back();
        used[v] = 1;
        for (auto x : a[v]){
            if (!used[x]){
                turn[x] = turn[v] ^ 1;
                st.push_back(x);
                p[x] = v;
            }
        }
    }
    reverse(all(order));
    vector<int> ans(n, 0), ans2(n, 0);
    for (int i = 0; i < n; i++){
        if (!turn[i]){
            ans[i] = n;
            ans2[i] = 1;
        } else {
            ans2[i] = n;
        }
    }
    for (auto v : order){
        if (a[v].size() == 1 && v){
            cnt[v] = 1;
            ans[v] = 1;
            ans2[v] = 1 - turn[v];
        }
        if (p[v] >= 0){
            cnt[p[v]] += cnt[v];
            if (turn[v]){
                ans2[v] = cnt[v] - ans2[v];
                ans[p[v]] = min(ans[p[v]], ans[v]);
                ans2[p[v]] += ans2[v] - 1;
            } else {
                ans[p[v]] += ans[v];
                ans2[p[v]] = min(ans2[p[v]], cnt[v] - ans2[v]);
            }
        }
    }

    // for (int i = 0; i < n; i++){
    //  cerr << ans2[i] << " ";
    // }
    // cerr << "\n";

    cout << cnt[0] - ans[0] + 1 << " " << cnt[0] - ans2[0] + 1 << "\n";

    return 0;
}