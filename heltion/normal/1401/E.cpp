#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 10;
int h[maxn];
void add(int x, int d){
    for(; x < maxn; x += x & -x) h[x] += d;
}
int sum(int x){
    int res = 0;
    for(; x; x -= x & -x) res += h[x];
    return res;
}
struct q{
    int type, x, y, l, r;
};
int y[maxn], lx[maxn], rx[maxn];
int x[maxn], ly[maxn], ry[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    LL ans = 1;
    for(int i = 0; i < n; i += 1){
        cin >> y[i] >> lx[i] >> rx[i];
        if(lx[i] == 0 and rx[i] == 1'000'000) ans += 1; 
    }
    //cout << ans << "\n";
    for(int i = 0; i < m; i += 1) cin >> x[i] >> ly[i] >> ry[i];
    vector<q> vq;
    for(int i = 0; i < m; i += 1) if(ly[i] == 0 and ry[i] < 1'000'000)
        vq.push_back({1, x[i], ry[i], 0, 0});
    for(int i = 0; i < n; i += 1) vq.push_back({0, 0, y[i], lx[i], rx[i]});
    sort(vq.begin(), vq.end(), [&](const q& a, const q& b){
        if(a.y != b.y) return a.y < b.y;
        if(a.type != b.type) return a.type < b.type;
        return false;
    });
    for(auto q : vq)
        if(q.type == 0){
            add(max(q.l, 1), 1);
            add(q.r + 1, -1);
        }
        else ans += sum(q.x);
    vq.clear();
    memset(h, 0, sizeof h);
    for(int i = 0; i < m; i += 1) if(ly[i] and ry[i] == 1'000'000)
        vq.push_back({1, x[i], ly[i], 0, 0});
    for(int i = 0; i < n; i += 1) vq.push_back({0, 0, y[i], lx[i], rx[i]});
    sort(vq.begin(), vq.end(), [&](const q& a, const q& b){
        if(a.y != b.y) return a.y > b.y;
        if(a.type != b.type) return a.type < b.type;
        return false;
    });
    for(auto q : vq){
        if(q.type == 0){
            add(max(q.l, 1), 1);
            add(q.r + 1, -1);
        }
        else ans += sum(q.x);
    }
    memset(h, 0, sizeof h);
    for(int i = 0; i < n; i += 1){
        add(max(lx[i], 1), 1);
        add(rx[i] + 1, -1);
    }
    for(int i = 0; i < m; i += 1) if(ly[i] == 0 and ry[i] == 1'000'000) ans += sum(x[i]) + 1;
    cout << ans;
    return 0;
}