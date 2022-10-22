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

namespace Mat {
const int N = 4;
int MOD;
struct Matrix {
int a[N][N];
Matrix () {
    memset(a, 0, sizeof a);
}   
int mul(int a, int b) {
    int ans = a * b % MOD;
    if (ans < 0)
        ans += MOD;
    return ans;
}   
void add(int &a, int b) {
    assert(a >= 0 && a < MOD);
    assert(b >= 0 && b < MOD);
    a += b;
    if (a >= MOD)
        a -= MOD;        
}   
Matrix (bool t) {
    memset(a, 0, sizeof a);
    for (int i = 0; i < N; ++i)
        a[i][i] = t;
}   
int * operator [] (int i) {
    return a[i];
}   
Matrix operator * (Matrix b) {
    Matrix ans;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                add(ans[i][j], mul(a[i][k], b[k][j]));
    return ans;
}   
void operator *= (Matrix b) {
    *this = *this * b;
}   
void print() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) 
            cout << a[i][j] << ' ';
        cout << '\n';
    }   
    cout << '\n';
}
Matrix operator ^ (int p) { 
    Matrix cur = *this;
    Matrix ans(1);
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) 
            ans *= cur;
        cur *= cur;
    }       
    return ans;
}   
void operator ^= (int p) {
    *this = *this ^ p;
}   
};
};

const int N = 1007;

// (x, y, z, 1)

int a[N][N], ans[N][N];
Mat::Matrix v[256];

void solve() {
    int n, m;
    cin >> n >> m;

    Mat::MOD = n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            a[i][j]--;
        }
        
    {
    v['R'] = Mat::Matrix(1);
    v['R'][3][1] = 1;
    }

    {
    v['L'] = Mat::Matrix(1);
    v['L'][3][1] = n - 1;
    }

    {
    v['D'] = Mat::Matrix(1);
    v['D'][3][0] = 1;
    }

    {
    v['U'] = Mat::Matrix(1);
    v['U'][3][0] = n - 1;
    }

    {
    v['I'] = Mat::Matrix(1);
    v['I'][1][1] = v['I'][2][2] = 0;
    v['I'][1][2] = v['I'][2][1] = 1;
    }

    {
    v['C'] = Mat::Matrix(1);
    v['C'][0][0] = v['C'][2][2] = 0;
    v['C'][0][2] = v['C'][2][0] = 1;
    }

    string s;
    cin >> s;
    Mat::Matrix cur(1);
    for (char c : s) {
        cur *= v[c];
    }   

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector <int> h = {i, j, a[i][j], 1};
            vector <int> res(3);
            for (int x = 0; x < 4; ++x)
                for (int y = 0; y < 3; ++y) {
                    res[y] += h[x] * cur[x][y];                                
                    res[y] %= n;
                }
            ans[res[0]][res[1]] = res[2];
        }   
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] + 1 << ' ';
        }   
        cout << endl;
    }   
    cout << endl;
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
    while (t--)
        solve();
}