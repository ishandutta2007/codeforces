#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
vector<vector<int>> A, B;

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        A.clear();
        B.clear();
        int res = 0;
        for(int i = n; i >= 1; i--){
                int x = 1, j = 0;
                A.clear();
                while(x <= a[i]){
                        A.push_back({a[i] / x, (x == 1), 0});
                        x = a[i] / A.back()[0] + 1;
                }
                for(int j = 0, k, need, h = 0; j < B.size(); j++){
                        k = (a[i] - 1) / B[j][0] + 1;
                        need = a[i] / k;
                        while(A[h][0] != need){
                                h += 1;
                        }

                        add(A[h][1], B[j][1]);
                        add(A[h][2], (1ll * B[j][1] * (k - 1) + B[j][2]) % mod);
                }
                for(int i = 0; i < A.size(); i++){
                        add(res, A[i][2]);
                }
                swap(A, B);
        }

        cout << res << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}