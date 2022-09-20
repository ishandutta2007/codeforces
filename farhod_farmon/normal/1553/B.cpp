#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 550;
const int mod = 31607;

using namespace std;

int n;
int m;
string s, t;
int L[N][2 * N];
int R[N][2 * N];

void solve()
{
        cin >> s >> t;
        n = s.size();
        m = t.size();

        s = "#" + s;
        t = "#" + t;

        for(int i = 0; i <= n + 1; i++){
                for(int j = 0; j <= m + 1; j++){
                        L[i][j] = R[i][j] = 0;
                }
        }

        for(int i = n; i >= 1; i--){
                for(int j = m; j >= 1; j--){
                        if(s[i] == t[j]){
                                R[i][j] = R[i + 1][j + 1] + 1;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = m; j >= 1; j--){
                        if(s[i] == t[j]){
                                L[i][j] = L[i - 1][j + 1] + 1;
                        }
                }
        }

        int res = 0;
        for(int i = 1; i <= n; i++){
                for(int x = 0; x + i <= n && x + 1 <= m; x++){
                        if(R[i][1] < x + 1){
                                continue;
                        }
                        res = max(res, x + 1 + L[i + x - 1][x + 2]);
                }
        }

        cout << (res == m ? "Yes" : "No") << "\n";
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