#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 66;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
bool A[N];
bool B[N];
char a[N][N];


void solve()
{
        cin >> n >> m;
        int res = 5;
        bool shit = false;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                        if(a[i][j] == 'A'){
                                res = 4;
                        } else{
                                shit = true;
                        }
                }
        }
        if(res == 5){
                cout << "MORTAL" << "\n";
                return;
        } else if(!shit){
                cout << 0 << "\n";
                return;
        }
        for(int i = 1; i <= n; i++){
                A[i] = true;
                for(int j = 1; j <= m; j++){
                        if(a[i][j] == 'P'){
                                A[i] = false;
                                break;
                        }
                }
        }
        for(int j = 1; j <= m; j++){
                B[j] = true;
                for(int i = 1; i <= n; i++){
                        if(a[i][j] == 'P'){
                                B[j] = false;
                                break;
                        }
                }
        }

        if(A[1] || A[n] || B[1] || B[m]){
                res = 1;
        }
        for(int i = 1; i <= n; i++){
                if(A[i]){
                        res = min(res, 2);
                }
        }
        for(int i = 1; i <= m; i++){
                if(B[i]){
                        res = min(res, 2);
                }
        }
        if(a[1][1] == 'A' || a[n][1] == 'A' || a[1][m] == 'A' || a[n][m] == 'A'){
                res = min(res, 2);
        }
        for(int i = 1; i <= n; i++){
                if(a[i][1] == 'A' || a[i][m] == 'A'){
                        res = min(res, 3);
                }
        }
        for(int i = 1; i <= m; i++){
                if(a[1][i] == 'A' || a[n][i] == 'A'){
                        res = min(res, 3);
                }
        }

        cout << res << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}