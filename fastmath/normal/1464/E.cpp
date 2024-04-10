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
#define debug(x) std::cout << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back

const int MOD = 998244353;
//need define int long long
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
int fp(int a, int p) {
    int ans = 1, c = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * c);
        c = mod(c * c);
    }   
    return ans;
}   
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }

struct M {
ll x;
M (int x_) {
    x = mod(x_);
}   
M () {
    x = 0;
}
M operator + (M y) {
    int ans = x + y.x;
    if (ans >= MOD)
        ans -= MOD;
    return M(ans);
}
M operator - (M y) {
    int ans = x - y.x;
    if (ans < 0)
        ans += MOD;
    return M(ans);            
}   
M operator * (M y) {
    return M(x * y.x % MOD);   
}   
M operator / (M y) {
    return M(x * fp(y.x, MOD - 2) % MOD);
}   
M operator + (int y) {
    return (*this) + M(y);
}
M operator - (int y) {
    return (*this) - M(y);
}   
M operator * (int y) {
    return (*this) * M(y);
}   
M operator / (int y) {
    return (*this) / M(y);
}   
M operator ^ (int p) {
    return M(fp(x, p));
}   
void operator += (M y) {
    *this = *this + y;
}   
void operator -= (M y) {
    *this = *this - y;
}   
void operator *= (M y) {
    *this = *this * y;
}
void operator /= (M y) {
    *this = *this / y;
}   
void operator += (int y) {
    *this = *this + y;
}   
void operator -= (int y) {
    *this = *this - y;
}   
void operator *= (int y) {
    *this = *this * y;
}
void operator /= (int y) {
    *this = *this / y;
}   
void operator ^= (int p) {
    *this = *this ^ p;
}
};  

namespace GG {
int mod = MOD;
struct GaussModulo {
    int mult(int a, int b){
        return a * (ll)b % mod;
    }

    int pow(int val, int deg){
        if (deg == 0) return 1;
        if (deg & 1) {
            return mult(val, pow(val, deg - 1));
        } else {
            int cur_val = pow(val, deg >> 1);
            return mult(cur_val, cur_val);
        }
    }

    int get_rev(int val) {
        return pow(val, mod - 2);
    }

    enum GaussSolution {
        ZERO, ONE, MANY
    };

    int n;
    GaussSolution solutions_cnt;
    vector<int> solutions;

    GaussModulo(vector< vector<int> > &eqs) {
        n = (int)eqs.back().size() - 1;
        solutions.resize(n);

        int cur_eq = 0;
        for (int v = 0; v < n; v++) {
            int correct_eq_num = -1;
            for (int eq_num = cur_eq; eq_num < eqs.size(); eq_num++) {
                if (eqs[eq_num][v] != 0) {
                    correct_eq_num = eq_num;
                    break;
                }
            }

            if (correct_eq_num == -1) continue;

            swap(eqs[cur_eq], eqs[correct_eq_num]);

            int rev_val = get_rev(eqs[cur_eq][v]);
            for (int i = v; i < eqs[cur_eq].size(); i++) {
                eqs[cur_eq][i] = mult(eqs[cur_eq][i], rev_val);
            }

            for (int eq_num = cur_eq + 1; eq_num < eqs.size(); eq_num++) {
                int cur_val = eqs[eq_num][v];
                for (int i = v; i < eqs[eq_num].size(); i++) {
                    eqs[eq_num][i] -= mult(eqs[cur_eq][i], cur_val);
                    if (eqs[eq_num][i] < 0) eqs[eq_num][i] += mod;
                }
            }

            cur_eq++;
        }

        if (cur_eq < n) {
            solutions_cnt = MANY;
            return;
        }

        for (int i = cur_eq; i < eqs.size(); i++) {
            if (eqs[i].back() != 0) {
                solutions_cnt = ZERO;
                return;
            }
        }

        for (int v = n - 1; v >= 0; v--) {
            for (int eq_num = v - 1; eq_num >= 0; eq_num--) {
                eqs[eq_num].back() -= mult(eqs[eq_num][v], eqs[v].back());
                if (eqs[eq_num].back() < 0) eqs[eq_num].back() += mod;
                eqs[eq_num][v] = 0;
            }
        }

        solutions_cnt = ONE;

        for (int v = 0; v < n; v++) solutions[v] = eqs[v].back();
    }
};

/*
equations in form : x0 * eq[i][0] + x1 * eq[i][1] ... + x[n - 1] * eq[i][n - 1] = eq[i][n]

how to use :
    GG::GaussModulo ga(eq);
    auto ans = ga.solutions;    
*/

};

const int N = 1e5+7, C = 1 << 9;

vector <int> g[N];

bool used[N];
int dp[N];
void dfs(int u) {
    used[u] = 1;
    vector <int> a = {-1, N};
    for (int v : g[u]) {
        if (!used[v]) {
            dfs(v);
        }   
        a.app(dp[v]);
    }   
    sort(all(a));
    for (int i = 0; i + 1 < a.size(); ++i) {
        if (a[i] + 1 < a[i + 1]) {
            dp[u] = a[i] + 1;
            break;
        }   
    }
    assert(dp[u] < C);
}   

int cnt[C];
M prob[C];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v);
    }               

    for (int i = 1; i <= n; ++i) {
        if (!used[i])
            dfs(i);
    }   

    #ifdef HOME
    for (int i = 1; i <= n; ++i)
        cout << dp[i] << ' ';
    cout << endl;
    #endif

    for (int i = 1; i <= n; ++i)
        cnt[dp[i]]++;
    for (int i = 0; i < C; ++i)
        prob[i] = M(cnt[i])/(n + 1);

    M end = M(1) / (n + 1);

    vector < vector <int> > eq(C, vector <int> (C + 1));
    for (int i = 0; i < C; ++i) {        
        eq[i][i] = 1;
        for (int j = 0; j < C; ++j) {
            M t = M(eq[i][j]) - M(prob[i ^ j]);
            eq[i][j] = t.x;
        }   
        if (i) {
            eq[i][C] = end.x;
        }   
    }   

    GG::GaussModulo ga(eq);
    auto ans = ga.solutions;    
    cout << ans[0] << endl;
}