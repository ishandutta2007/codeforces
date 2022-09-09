#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
int a[maxn + 1], b[maxn + 1];
struct node{
    int v, c, p, t;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, x, y;
        cin >> n >> x >> y;
        map<int, int> mp;
        vector<node> v;
        for(int i = 1; i <= n; i += 1){
            cin >> b[i];
            mp[b[i]] += 1;
            v.push_back({b[i], mp[b[i]], i});
        }
        int m = 0;
        for(auto [p, q] : mp) m = max(m, q);
        set<int> s;
        for(int i = 1; i <= n + 1; i += 1) s.insert(i);
        for(int i = 1; i <= n; i += 1) s.erase(b[i]);

        sort(v.begin(), v.end(), [](const node& n1, const node& n2){
            return n1.c == n2.c ? n1.p < n2.p : n1.c > n2.c;
        });
        for(int i = 0; i < x; i += 1) a[v[i].p] = v[i].v;
        for(int i = x; i < n - (y - x); i += 1) v[i].t = 1;
        sort(v.begin() + x, v.end(), [](const node& n1, const node& n2){
            return n1.v == n2.v ? n1.t > n2.t : n1.v < n2.v;
        });
        map<int ,int> mp2;
        for(int i = x; i < n; i += 1) if(v[i].t == 0) mp2[v[i].v] += 1;
        int m2 = 0;
        for(auto [p, q] : mp2) m2 = max(m2, q);
        for(int i = x; i < n; i += 1) a[v[(i - x + m2) % (n - x) + x].p] = v[i].t ? *s.begin() : v[i].v;
        int xx = 0;
        for(int i = 1; i <= n; i += 1) xx += a[i] == b[i];
        if(xx != x){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 1; i <= n; i += 1) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}