#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
ll MOD = 1000 * 1000 * 1000 + 7;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    vector <string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector <vector <ll> > dp(n);
    for (int i = 0; i < n; ++i)
        dp[i].resize(a[i].size());
    vector <ll> al(n);

    for (ll &e : dp[0])
        e = 1;
    al[0] = 1;
    
    const int INF = 1e9;

    auto build = [&] (int who) {
        vector <int> p;
        for (int j = 0; j < a[who].size(); ++j)   
            p.app(j);

        int len = a[who].size();
        vector <int> lcp(len);
        for (int i = len - 2; i >= 0; --i) {
            if (a[who][i] == a[who][i+1])
                lcp[i] = lcp[i+1]+1;
            else
                lcp[i] = 0;
        }

        auto comp = [&] (int i, int j) {
            if (i < j) {
                int t = lcp[i];
                if (t >= j - i)
                    return false;
                else
                    return a[who][i+t+1] < a[who][i+t];
            }   
            else {
                int t = lcp[j];
                if (t >= i - j) 
                    return false;
                else
                    return a[who][j+t] < a[who][j+t+1];
            }
        };  
        sort(all(p), comp);
        return p;        
    };  

    vector <vector <int> > p(n);
    for (int i = 0; i < n; ++i)
        p[i] = build(i);

    auto add = [&] (ll &a, ll b) {
        a += b;
        if (a >= MOD)   
            a -= MOD;
    };

    auto get = [&] (int i, int p) {
        return a[i].substr(0, p) + a[i].substr(p + 1, (int)a[i].size() - p - 1);
    };  
    auto cmp1 = [&] (int i, int pi, int j) {
        return get(i, pi) < a[j];
    };
    auto cmp2 = [&] (int i, int j, int pj) {
        return a[i] < get(j, pj);
    };  

    for (int i = 1; i < n; ++i) {

        string aa = a[i-1];
        string bb = a[i];
        while (aa.size() < bb.size())
            aa += '#';
        while (bb.size() < aa.size())
            bb += '#';
        
        int len = aa.size();
        vector <int> lcp(len+1);
        for (int i = len - 1; i >= 0; --i)
            if (aa[i] == bb[i])
                lcp[i] = lcp[i+1]+1;
            else
                lcp[i] = 0;

        vector <int> lcp1(len);
        for (int i = len - 2; i >= 0; --i)
            if (aa[i] == bb[i+1])
                lcp1[i] = lcp1[i+1]+1;
            else
                lcp1[i] = 0;

        vector <int> lcp2(len);
        for (int i = len - 2; i >= 0; --i)
            if (bb[i] == aa[i+1])
                lcp2[i] = lcp2[i+1]+1;
            else    
                lcp2[i] = 0;

        auto cmp = [&] (int pi, int pj) {
            if (pi < pj) {
                if (lcp[0] < pi) {
                    return bb[lcp[0]] < aa[lcp[0]];
                }
                else if (lcp1[pi] < pj - pi) {
                    return bb[pi+lcp1[pi]+1] < aa[pi+lcp1[pi]];
                }
                else if (lcp[pj+1] < len - (pj + 1)) {
                    return bb[pj+1+lcp[pj+1]] < aa[pj+1+lcp[pj+1]];
                }
                else {
                    return false;
                }   
            }   
            else {
                if (lcp[0] < pj) {
                    return bb[lcp[0]] < aa[lcp[0]];                    
                }
                else if (lcp2[pj] < pi - pj) {
                    return bb[pj+lcp2[pj]] < aa[pj+lcp2[pj]+1];
                }   
                else if (lcp[pi+1] < len - (pi + 1)) {
                    return bb[pi+1+lcp[pi+1]] < aa[pi+1+lcp[pi+1]];
                }   
                else {
                    return false;
                }   
            }   
        };  

        int ptr = 0; //first >
        ll sum = 0;
        for (int j = 0; j < a[i].size(); ++j) {
            while (ptr < a[i-1].size() && !cmp(p[i][j], p[i-1][ptr])) {
                add(sum, dp[i-1][ptr]);
                ptr++;
            }            
            dp[i][j] = sum;
        }

        {
        int l = -1, r = a[i].size();
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (!cmp1(i, p[i][m], i-1))
                r = m;
            else
                l = m;
        }   
        for (int j = r; j < a[i].size(); ++j)
            add(dp[i][j], al[i-1]);            
        }
        
        {
        int l = -1, r = a[i-1].size();
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (!cmp2(i, i - 1, p[i-1][m]))
                l = m;
            else
                r = m;
        }   
        for (int j = 0; j <= l; ++j)
            add(al[i], dp[i-1][j]);
        }

        if (a[i-1] <= a[i]) {
            add(al[i], al[i-1]);
        }       
    }   
    
    #ifdef HOME
    for (int i = 0; i < n; ++i) {
        for (auto e : dp[i])
            cout << e << ' ';
        cout << al[i] << endl;
    }   
    #endif

    ll ans = 0;
    for (ll &e : dp.back())
        ans += e;
    ans += al.back();
    cout << ans % MOD << endl;
}