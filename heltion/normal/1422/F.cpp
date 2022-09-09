#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
LL power(LL a, LL r){
    LL res = 1;
    for(; r; r >>= 1, a = a * a % mod)
        if(r & 1) res = res * a % mod;
    return res;
}
struct Node{
    int sum, ls, rs;
}nodes[30000000];
constexpr int maxn = 200000 + 1;
stack<pair<int, int>> sp[maxn];
vector<pair<int, int>> d[maxn];
int root[maxn], tot = 0;
#define tm ((tl + tr) >> 1)
void build(int& v, int tl, int tr){
    v = tot += 1;
    nodes[v].sum = 1;
    if(tl < tr){
        build(nodes[v].ls, tl, tm);
        build(nodes[v].rs, tm + 1, tr);
    }
}
void modify(int o, int& cur, int tl, int tr, int p, LL d){
    cur = tot += 1;
    nodes[cur] = nodes[o];
    nodes[cur].sum = nodes[cur].sum * d % mod;
    if(tl < tr){
        if(p <= tm) modify(nodes[cur].ls, nodes[cur].ls, tl, tm, p, d);
        else modify(nodes[cur].rs, nodes[cur].rs, tm + 1, tr, p, d);
    }
}
LL query(int o, int tl, int tr, int L, int R){
    if(tl >= L and tr <= R) return nodes[o].sum;
    LL res = 1;
    if(L <= tm) res *= query(nodes[o].ls, tl, tm, L, R);
    if(R > tm) res *= query(nodes[o].rs, tm + 1, tr, L, R);
    return res % mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i = 2; i < maxn; i += 1)
        if(d[i].empty()){
            for(int j = i; j < maxn; j += i){
                d[j].push_back({i, 0});
                for(int k = j; k % i == 0; k /= i) d[j].back().second += 1;
            }
        }
    int n;
    cin >> n;
    build(root[0], 1, n);
    for(int i = 1, a; i <= n; i += 1){
        cin >> a;
        root[i] = root[i - 1];
        for(auto p : d[a]){
            int v = p.first, r = p.second, k = r;
            while(not sp[v].empty() and k){
                int h = min(sp[v].top().second, k);
                k -= h;
                sp[v].top().second -= h;
                modify(root[i], root[i], 1, n, sp[v].top().first, power(power(v, mod - 2), h));
                //cout << i << " " << sp[v].top().first << " " << v << " " << h << "\n";
                if(not sp[v].top().second) sp[v].pop();
            }
            modify(root[i], root[i], 1, n, i, power(v, r));
            sp[v].push({i, r});
            //cout << i << " " << i << " " << v << " " << r << "\n";
        }
    }
    int q, last = 0;
    for(cin >> q; q; q -= 1){
        int x, y;
        cin >> x >> y;
        int l = (last + x) % n + 1, r = (last + y) % n + 1;
        if(l > r) swap(l, r);
        //cout << l << " " << r << "\n";
        cout << (last = query(root[r], 1, n, l, r)) << "\n";
    }
    return 0;
}