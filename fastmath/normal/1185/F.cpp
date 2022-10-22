#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int sum[N];
int cost[N];
vector <int> a[N];
bool comp(int i, int j) {
    return cost[i] < cost[j];
}   
int ans = -1, x, y;
void upd(int ans1, int x1, int y1) {
    if (ans1 > ans || (ans1 == ans && cost[x1] + cost[y1] < cost[x] + cost[y])) {
        ans = ans1;
        x = x1;
        y = y1;
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        int mask = 0;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            --x;
            mask += 1 << x;
        }   
        sum[mask]++;
    }   
    for (int mask = (1 << 9) - 1; mask >= 0; --mask) {
        for (int t = 0; t < mask; ++t) {
            if ((mask & t) == t) {
                sum[mask] += sum[t];
            }   
        }   
    }   
    for (int i = 0; i < m; ++i) {
        cin >> cost[i];
        int k;
        cin >> k;
        int mask = 0;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            --x;
            mask += 1 << x;
        }
        a[mask].app(i);
    }   
    for (int i = 0; i < N; ++i) {
        sort(all(a[i]), comp);
        if (a[i].size() > 1) {
            upd(sum[i], a[i][0], a[i][1]);            
        }   
    }   
    for (int i = 0; i < (1 << 9); ++i) {
        for (int j = i + 1; j < (1 << 9); ++j) {
            if (a[i].size() && a[j].size())
                upd(sum[i | j], a[i][0], a[j][0]);
        }   
    }   
    cout << x + 1 << ' ' << y + 1 << '\n';
}