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

const int N = 1007;
bool dp[N][11][11];
int prv[N][11][11];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    string s;
    cin >> s;
    int m;
    cin >> m;

    dp[0][0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= 10; ++j) {
            for (int k = 0; k <= 10; ++k) {
                if (dp[i][j][k]) {

                    //cout << i << ' ' << j << ' ' << k << endl;

                    for (int add = k + 1; add <= 10; ++add) {
                        if (s[add - 1] == '1' && add != j) {
                            dp[i + 1][add][add - k] = 1;
                            prv[i + 1][add][add - k] = j;
                        }   
                    }   
                }   
            }   
        }   
    }   
    
    for (int c = 1; c <= 10; ++c) {
        for (int d = 1; d <= 10; ++d) {
            if (dp[m][c][d]) {

                vector <int> ans;
                for (int i = m; i; --i) {
                    ans.app(c);
                    int d1 = abs(d - c);
                    c = prv[i][c][d];
                    d = d1;
                }   
                reverse(all(ans));
                cout << "YES" << endl;
                for (auto e : ans)
                    cout << e << ' ';
                cout << endl;
                exit(0);

            }   
        }   
    }   
    cout << "NO" << endl;
}