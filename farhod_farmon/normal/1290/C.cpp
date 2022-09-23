#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 600300;
const int mod = 998244353;

using namespace std;

int n;
int k;
int a[N];
int p[N];
int A[N];
int B[N];
int can[N];
int best[N];
vector < int > v[N];
vector < int > g[N];
int all;
string s;

int get(int x)
{
        return x == p[x] ? x : p[x] = get(p[x]);
}

void make(int x)
{
        x = get(x);
        all -= best[x];
        best[x] = 1e9;
        if(can[x] & 1){
                best[x] = min(best[x], A[x]);
        }
        if(can[x] & 2){
                best[x] = min(best[x], B[x]);
        }
        all += best[x];
}

int comb(int x, int y, int ch)
{
        x = get(x);
        y = get(y);
        all -= best[x];
        all -= best[y];
        best[x] = best[y] = 0;

        if(g[x].size() > g[y].size()){
                swap(x, y);
        }

        p[x] = y;
        for(int z: g[x]){
                g[y].push_back(z);
                a[z] ^= ch;
        }
        can[y] = min(can[y], can[x]);
        if(ch > 0){
                A[y] += B[x];
                B[y] += A[x];
                if(can[x] < 3){
                        can[y] = can[x] ^ ch;
                }
        } else{
                A[y] += A[x];
                B[y] += B[x];
        }
        make(y);
        g[x].clear();
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> k >> s;
        for(int i = 1; i <= k; i++){
                int l;
                cin >> l;
                for(int j = 1; j <= l; j++){
                        int x;
                        cin >> x;
                        v[x - 1].push_back(i);
                }
        }
        int fict = N / 2;
        for(int i = 0; i < N; i++){
                p[i] = i;
                can[i] = 3;
                g[i] = {i};
                A[i] = (i < N / 2);
                best[i] = 0;
                a[i] = 1;
        }

        for(int i = 0; i < n; i++){
                if(v[i].size() == 1){
                        int x = v[i][0];
                        int par = get(x);

                        can[par] = a[x];
                        if(s[i] == '1'){
                                can[par] = a[x] ^ 3;
                        }
                        make(par);
                } else if(v[i].size() == 2){
                        int x = v[i][0], y = v[i][1], px = get(x), py = get(y);

                        if(px != py){
                                if(s[i] == '0'){
                                        if(a[x] != a[y]){
                                                comb(px, py, 0);
                                        } else{
                                                comb(px, py, 3);
                                        }
                                } else{
                                        if(a[x] != a[fict]){
                                                comb(px, fict, 0);
                                        } else{
                                                comb(px, fict, 3);
                                        }
                                        if(a[y] != a[fict]){
                                                comb(py, fict, 0);
                                        } else{
                                                comb(py, fict, 3);
                                        }
                                        fict += 1;
                                }
                        }
                }
                cout << all << "\n";
        }
}