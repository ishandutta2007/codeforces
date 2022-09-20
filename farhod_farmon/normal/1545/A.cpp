#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];
int b[N];
int d[N][4];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        for(int i = 0; i < N; i++){
                for(int j = 0; j < 4; j++){
                        d[i][j] = 0;
                }
        }
        for(int i = 1; i <= n; i++){
                d[a[i]][i % 2]++;
                d[b[i]][2 + i % 2]++;
        }
        for(int i = 0; i < N; i++){
                if(d[i][0] != d[i][2] || d[i][1] != d[i][3]){
                        cout << "NO" << "\n";
                        return;
                }
        }
        cout << "YES" << "\n";
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