#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

void solve()
{
        int n, m;
        cin >> n >> m;
        vector < vector < char > > a(n, vector < char > (m));
        int tp = -1;
        bool good = true;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        cin >> a[i][j];
                        int x = -1;
                        if(a[i][j] == 'R'){
                                x = (i + j) % 2;
                        } else if(a[i][j] == 'W'){
                                x = 1 - (i + j) % 2;
                        }
                        if(x != -1){
                                if(tp != -1 && tp != x){
                                        good = false;
                                }
                                tp = x;
                        }
                }
        }
        if(tp == -1){
                tp = 0;
        }
        if(!good){
                cout << "NO" << "\n";
                return;
        }
        cout << "YES" << "\n";
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        if(tp == (i + j) % 2){
                                cout << "R";
                        } else{
                                cout << "W";
                        }
                }
                cout << "\n";
        }
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