#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#define fi first
#define se second

const int N = 300300;
const int Q = 100100;
const int MAGIC = 130;

using namespace std;

int n;
int q;
int a[N];
int last[20];
int f[N][20];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 0; i < 20; i++){
                last[i] = n + 1;
                f[n + 1][i] = n + 1;
        }
        vector < int > v;
        for(int i = n; i >= 1; i--){
                v.clear();
                for(int j = 0; j < 20; j++){
                        if(a[i] & (1 << j)){
                                f[i][j] = i;
                                v.push_back(last[j]);
                                last[j] = i;
                        } else{
                                f[i][j] = n + 1;
                        }
                }
                for(int j = 0; j < 20; j++){
                        if(a[i] & (1 << j)){
                                continue;
                        }
                        for(int x: v){
                                f[i][j] = min(f[i][j], f[x][j]);
                        }
                }
        }
        for(int i = 1; i <= q; i++){
                int x, y;
                cin >> x >> y;
                int res = n + 1;
                for(int j = 0; j < 20; j++){
                        if(a[y] & (1 << j)){
                                res = min(res, f[x][j]);
                        }
                }
                if(res <= y){
                        cout << "Shi" << "\n";
                } else{
                        cout << "Fou" << "\n";
                }
        }
}