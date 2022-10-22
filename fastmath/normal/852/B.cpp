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

const int N = 101, MOD = 1000 * 1000 * 1000 + 7, K = 1e6 + 7;

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
void add(int &a, int b) { a = mod(a + b); }
int dv(int a, int b) { return mod(a * fp(b, MOD - 2)); }

int cnt[N];
int cl[K], c[K], cr[K];
int a[N][N];

void clear(int a[N][N], bool t) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = t * (i == j);
}   
void cop(int a[N][N], int b[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = b[i][j];
}   
int t[N][N];
int n, L, M;
void add(int a[N][N], int b[N][N]) {
    clear(t, 0);
    for (int i = 0; i < 1; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < M; ++k)
                add(t[i][j], a[i][k] * b[k][j]);
    for (int i = 1; i < M; ++i)
        for (int j = 0; j < M; ++j)
            t[i][j] = t[0][(j + M - i) % M];
    cop(a, t);
}   
void print(int a[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) 
            cout << a[i][j] << ' ';
        cout << '\n';
    }   
    cout << '\n';
}
int ans[N][N], cur[N][N];
void fp(int a[N][N], int p) {
    cop(cur, a);
    clear(ans, 1);
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) 
            add(ans, cur);
        add(cur, cur);
    }       
    cop(a, ans);
}
   
int l[N], r[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> L >> M;
    for (int i = 0; i < n; ++i) 
        cin >> cl[i];
    for (int i = 0; i < n; ++i) 
        cin >> c[i];
    for (int i = 0; i < n; ++i) 
        cin >> cr[i];
    for (int i = 0; i < n; ++i)
        ++cnt[c[i] % M];
    for (int i = 0; i < M; ++i) 
        for (int j = 0; j < M; ++j)
            a[i][(i + j) % M] = cnt[j];

    for (int i = 0; i < n; ++i)
        ++l[cl[i] % M];
    for (int i = 0; i < n; ++i)
        ++r[(cr[i] + c[i]) % M];

    fp(a, L - 2);
    int ans = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            int w = ((-i-j)%M+M)%M;//((-cl[i]-cr[j]-c[j])%M+M)%M;
            add(ans, a[0][w] * mod(l[i] * r[j]));
        }   
    }   
    cout << ans << '\n';
}