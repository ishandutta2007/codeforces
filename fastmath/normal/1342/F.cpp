#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 16, INF = 1e9 + 7;
int dp[N][1 << N], par[N][1 << N];
int sum[1 << N];

void calc(int del, vector <int> &a) {
    vector <int> d, h;
    for (int i = 0; i < a.size(); ++i) {
        if ((del >> i) & 1)
            d.app(i);
        else
            h.app(i);
    }   
    int all = (1 << d.size()) - 1;

    for (int mask = 0; mask <= all; ++mask) {
        sum[mask] = 0;
        for (int i = 0; i < d.size(); ++i)
            if ((mask >> i) & 1)
                sum[mask] += a[d[i]];
    }   

    for (int i = 0; i < N; ++i)
        for (int mask = 0; mask <= all; ++mask)
            dp[i][mask] = INF;

    dp[0][all] = 0;
    for (int i = 0; i < h.size(); ++i) {
        int val = a[h[i]];
        for (int mask = 0; mask <= all; ++mask) {
            if (dp[i][mask] == INF)
                continue;
            for (int s=mask; ; s=(s-1)&mask) {
                if (dp[i][mask] < val + sum[s] && val + sum[s] < dp[i + 1][mask ^ s]) {
                    dp[i + 1][mask ^ s] = val + sum[s];
                    par[i + 1][mask ^ s] = mask;
                }   
                if (s == 0)
                    break;
            }        
        }   
    }   
}

bool check(int del, vector <int> &a) {
    calc(del, a);
    return dp[(int)a.size() - bp(del)][0] != INF;
}

int to[N];
bool used[N];
void print(int del, vector <int> &a) {
    for (int i = 0; i < N; ++i)
        to[i] = -1;
    memset(used, 0, sizeof used);

    cout << bp(del) << endl;
    calc(del, a);

    vector <int> d, h;
    for (int i = 0; i < a.size(); ++i) 
        if ((del >> i) & 1)
            d.app(i);
        else
            h.app(i);

    int ci = h.size(), cm = 0;
    while (ci) {
        int add = par[ci][cm] ^ cm;
        for (int i = 0; i < d.size(); ++i)  
            if ((add >> i) & 1) {
                to[d[i]] = h[ci - 1];
            }

        cm = par[ci][cm];
        ci--;
    }   

    for (int tak = 0; tak < d.size(); ++tak) {
        for (int i = 0; i < a.size(); ++i) {
            if (((del >> i) & 1) && !used[i]) {
                int num1 = 0;
                for (int j = 0; j < i; ++j)
                    num1 += !used[j];

                int num2 = 0;
                for (int j = 0; j < to[i]; ++j)
                    num2 += !used[j];
                cout << num1 + 1 << ' ' << num2 + 1 << endl;
                used[i] = 1;
                break;
            }   
        }   
    }   
}   

bool comp(int a, int b) {
    return bp(a) < bp(b);
}   
void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector <int> v;
    for (int i = 0; i < (1 << n); ++i)
        v.app(i);
    sort(all(v), comp);
    for (int del : v) {
        if (check(del, a)) {
            print(del, a);
            return;
        }   
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
}