#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7, LG=20;
int a[N], pref[N];
vector <int> pos[100];

int sp[LG][N];
int pw[N];

int getmax(int l, int r) {
    int p = pw[r - l + 1];
    return max(sp[p][l], sp[p][r - (1 << p) + 1]);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int p = 0;
    for (int i = 0; i < N; ++i) {
        while ((1 << (p + 1)) < i)
            ++p;
        pw[i] = p;                
    }   
        
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];
    for (int i = 0; i < n; ++i)
        pos[a[i] + 30].app(i);


    for (int i = 1; i <= n; ++i) {
        sp[0][i] = pref[i];
    }   
    for (int p = 1; p < LG; ++p)
        for (int i = 1; i + (1 << p) - 1 <= n; ++i)
            sp[p][i] = max(sp[p - 1][i], sp[p - 1][i + (1 << (p -1))]);

    int ans = -1e9;
    for (int l = 0; l < n; ++l) {
        int mem = n;
        for (int mx = 30; mx >= -30; --mx) {
            auto t = lower_bound(all(pos[mx + 30]), l);
            if (t == pos[mx + 30].end() || *t > mem)
                continue;

            //l <= r < mem
            int best = getmax(l + 1, mem);
            ans = max(ans, best - pref[l] - mx);
            mem = *t;
        }   
    }
    cout << ans << endl; 
}