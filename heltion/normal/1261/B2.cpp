#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int a[maxn], ans[maxn];
vector<pair<int, int>> v[maxn];
int s[maxn];
void add(int x, int n){
    for(; x <= n; x += x & -x) s[x] += 1;
}
int sum(int x){
    int res = 0;
    for(; x; x -= x & -x) res += s[x];
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    for(int i = 1; i <= n; i += 1){
        cin >> a[i];
        p.push_back({a[i], -i});
    }
    sort(p.begin(), p.end(), greater<pair<int, int>>());
    int m;
    cin >> m;
    for(int i = 1; i <= m; i += 1){
        int k, pos;
        cin >> k >> pos;
        v[k].push_back({pos, i});
    }
    for(int i = 1; i <= n; i += 1){
        add(-p[i - 1].second, n);
        for(auto p : v[i]){
            int pos = p.first, id = p.second;
            int L = 1, R = n;
            while(L < R){
                int M = (L + R) >> 1;
                int x = sum(M);
                if(x > pos) R = M - 1;
                else if(x == pos) R = M;
                else L = M + 1;
            }
            ans[id] = a[L];
        }
    }
    for(int i = 1; i <= m; i += 1) cout << ans[i] << "\n";
    return 0;
}