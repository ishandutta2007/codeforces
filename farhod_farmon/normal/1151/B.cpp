#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 555;

using namespace std;

int n;
int m;
int res[N];
int a[N][N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        int f = 0;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                }
                f ^= a[i][1];
                res[i] = 1;
        }
        if(f == 0){
                for(int i = 1; i <= n; i++){
                        for(int j = 2; j <= m; j++){
                                if(f > 0){
                                        break;
                                }
                                if((f ^ a[i][1] ^ a[i][j]) > 0){
                                        f = 1;
                                        res[i] = j;
                                        break;
                                }
                        }
                }
        }
        if(f == 0){
                cout << "NIE" << "\n";
        } else{
                cout << "TAK" << "\n";
                for(int i = 1; i <= n; i++){
                        cout << res[i] << " ";
                }
        }
}