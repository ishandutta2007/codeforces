#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int a[maxn];
struct Trap{
    int l, r, d;
    bool operator < (const Trap& trap){return d > trap.d;}
}trap[maxn];
LL sum = 0;
set<pair<int, int>> s;
void add(int L, int R){
    auto it = s.lower_bound({L, 0});
    if(it != s.begin()){
        it --;
        if(it->second >= L){
            int l = it->first, r = it->second;
            sum -= r - l + 1;
            s.erase(it);
            add(l, max(r, R));
            return;
        }
    }
    it = s.lower_bound({L, 0});
    if(it != s.end()){
        if(it->first <= R){
            int l = it->first, r = it->second;
            sum -= r - l + 1;
            s.erase(it);
            add(L, max(r, R));
            return;
        }
    }
    s.insert({L, R});
    sum += R - L + 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    for(int i = 1; i <= m; i += 1) cin >> a[i];
    sort(a + 1, a + m + 1, greater<int>());
    for(int i = 1; i <= k; i += 1) cin >> trap[i].l >> trap[i].r >> trap[i].d;
    int ans = 0;
    sort(trap + 1, trap + k + 1);
    for(int i = 1, j = 1; i <= m; i += 1){
        for(;j <= k and trap[j].d > a[i]; j += 1) add(trap[j].l, trap[j].r);
        if(2 * sum + n + 1 <= t) ans = i;
    }
    cout << ans;
    return 0;
}