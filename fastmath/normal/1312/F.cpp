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
const int N = 1001;
int mex(vector <int> a) {
    set <int> ms;
    for (int e : a)
        ms.insert(e);
    for (int i = 0; ; ++i)
        if (ms.find(i) == ms.end())
            return i;
}   
vector <int> pre[6][6][6][3], per[6][6][6][3];
int dp[N][3];
void calc(int op[3]) {
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            vector <int> mem;
            for (int k = 0; k < 3; ++k) {
                if (j == k && j < 2) 
                    continue;
                int x = max(0ll, i - op[k]);
                mem.app(dp[x][k]);
            }   
            dp[i][j] = mex(mem);
        }   
    }       
    for (int last = 0; last < 3; ++last) {
        vector <int> &a = pre[op[0]][op[1]][op[2]][last];
        vector <int> &b = per[op[0]][op[1]][op[2]][last];

        for (int i = 0; i < 50 && b.empty(); ++i) {
            for (int j = 1; j < 20; ++j) {
                bool ch = 1;
                for (int s = i; s + j - 1 < N; s += j) {
                    for (int k = 0; k < j; ++k)
                        ch &= dp[s + k][last] == dp[i + k][last];
                    if (!ch)
                        break;
                }   
                if (ch) {
                    for (int k = 0; k < i; ++k)
                        a.app(dp[k][last]);
                    for (int k = i; k < i + j; ++k)
                        b.app(dp[k][last]);
                    break;
                }   
            }   
        }   

        if (b.empty()) {
            cout << "not found\n";
            for (int i = 0; i < 3; ++i)
                cout << op[i] << ' ';
            cout << endl;
            cout << last << endl;
            for (int i = 0; i <= 40; ++i)
                cout << dp[i][last] << ' ';
            cout << endl;
            exit(0);
        }   
    }
}   
int cur[3];
void gen(int i) {
    if (i == 3) {
        calc(cur);
        return;
    }   
    for (int x = 1; x <= 5; ++x) {
        cur[i] = x;
        gen(i + 1);
    }   
}   

int get(int x, int op[3], int last) {
    vector <int> &a = pre[op[0]][op[1]][op[2]][last];
    vector <int> &b = per[op[0]][op[1]][op[2]][last];
    if (x < a.size())
        return a[x];
    else
        return b[(x - a.size()) % b.size()];
}   

const int NN = 5e5 + 7;
int a[NN], pref[NN], post[NN];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    gen(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int op[3];
        cin >> op[2] >> op[0] >> op[1];

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 0; i < n; ++i)
            pref[i + 1] = pref[i] ^ get(a[i], op, 2);
        post[n] = 0;
        for (int i = n - 1; i >= 0; --i)
            post[i] = post[i + 1] ^ get(a[i], op, 2);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                int to = max(0ll, a[i] - op[j]);
                ans += (pref[i] ^ post[i + 1] ^ get(to, op, j)) == 0;
                /*
                if ((pref[i] ^ post[i + 1] ^ get(to, op, j)) == 0) {
                    cout << "add " << i << ' ' << j << endl;
                }
                */  
            }   
        }   
        cout << ans << endl;
    }   

}