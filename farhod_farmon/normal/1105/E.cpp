#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 44;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int q;
int G;
int col[N];
int c[N][N];
int f[N][N];
int d[1 << 21];
bool used[N];
map < string, int > id;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("tracking2.in", "r", stdin);
        //freopen("tracking2.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> q >> n;
        for(int i = 1; i <= q; i++){
                int t;
                cin >> t;
                if(t == 1){
                        for(int j = 0; j < n; j++){
                                used[j] = 0;
                        }
                }
                else{
                        int x;
                        string s;
                        cin >> s;
                        if(id.find(s) == id.end()){
                                id[s] = G;
                                G += 1;
                        }
                        x = id[s];
                        used[x] = 1;
                        for(int j = 0; j < n; j++){
                                if(j != x){
                                        c[x][j] |= used[j];
                                }
                        }
                }
        }
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        c[i][j] |= c[j][i];
                }
        }
        int l = n / 2;
        for(int i = 0; i < (1 << l); i++){
                int ms = 0;
                for(int j = 0; j < l; j++){
                        if(i & (1 << j)){
                                d[i] = max(d[i], d[i ^ (1 << j)]);
                                for(int h = 0; h < l; h++){
                                        if(c[j][h]){
                                                ms |= (1 << h);
                                        }
                                }
                        }
                }
                if(ms & i){
                        continue;
                }
                d[i] = __builtin_popcount(i);
        }
        int res = d[(1 << l) - 1];
        int r = n - l;
        for(int i = 0; i < (1 << r); i++){
                int ms2 = 0, ms1 = 0;
                for(int j = 0; j < r; j++){
                        if(i & (1 << j)){
                                for(int h = 0; h < r; h++){
                                        if(c[j + l][h + l]){
                                                ms1 |= (1 << h);
                                        }
                                }
                                for(int h = 0; h < l; h++){
                                        if(c[j + l][h]){
                                                ms2 |= (1 << h);
                                        }
                                }
                        }
                }
                if(ms1 & i){
                        continue;
                }
                ms2 ^= (1 << l) - 1;
                res = max(res, __builtin_popcount(i) + d[ms2]);
        }
        cout << res << "\n";
}