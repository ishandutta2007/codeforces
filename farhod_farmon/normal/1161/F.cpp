#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
const long long mod = 998244353;

using namespace std;

int n;
int d[N][N];
int f[N][N];
int a[N][N];
int A[N];
int B[N];
int l[N];
int pref[N][N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cin >> a[i][j];
                }
                l[i] = 0;
                A[i] = B[i] = 0;
        }
        int st;
        char tp;
        cout << "B" << endl;
        cin >> tp >> st;

        if(tp == 'D'){
                for(int i = 1; i <= n; i++){
                        for(int j = 1; j <= n; j++){
                                a[i][j] *= -1;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        d[i][j] = j;
                        f[i][j] = j;
                }
        }
        if(st <= n){
                for(int i = 1; i <= n; i++){
                        sort(d[i] + 1, d[i] + n + 1, [&i](int x, int y){
                                return a[i][x] < a[i][y];
                        });
                        sort(f[i] + 1, f[i] + n + 1, [&i](int x, int y){
                                return a[x][i] > a[y][i];
                        });
                }
        } else{
                for(int i = 1; i <= n; i++){
                        sort(d[i] + 1, d[i] + n + 1, [&i](int x, int y){
                                return a[i][x] > a[i][y];
                        });
                        sort(f[i] + 1, f[i] + n + 1, [&i](int x, int y){
                                return a[x][i] < a[y][i];
                        });
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        pref[i][f[i][j]] = j;
                }
        }

        while(true){
                int x = -1;
                for(int i = 1; i <= n; i++){
                        if(!A[i]){
                                x = i;
                                break;
                        }
                }
                if(x == -1){
                        break;
                }
                l[x] += 1;
                assert(l[x] <= n);
                int z = d[x][l[x]];
                int y = B[z];
                if(!B[z]){
                        B[z] = x;
                        A[x] = z;
                } else if(pref[z][x] < pref[z][y]){
                        B[z] = x;
                        A[x] = z;
                        A[y] = 0;
                }
        }

        while(true){
                if(st > n){
                        cout << B[st - n] << endl;
                } else{
                        cout << A[st] + n << endl;
                }
                cin >> st;
                if(st == -1){
                        break;
                } else if(st == -2){
                        exit(0);
                }
        }
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