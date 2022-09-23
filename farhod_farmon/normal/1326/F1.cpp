#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 15;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
int c[N][N];
int all;

vector < int > A[1 << N - 1][N], B[1 << N - 1][N];
vector < int > v[N];

vector < int > fre[1 << N - 1];
int l[1 << N - 1];
long long d[1 << N - 1][N];
long long res[1 << N - 1];

void solve(int mask, int cur)
{
        if(cur == n - 1){
                for(int i = 0; i < n; i++) res[mask] += d[all - 1][i];
                return;
        }
        for(int g: {0, 1}){
                if(g == 0){
                        for(int j: v[cur + 1]){
                                for(int h: fre[j]){
                                        for(int z: B[j][h]){
                                                d[j | (1 << z)][z] += d[j][h];
                                        }
                                }
                        }
                } else{
                        for(int j: v[cur + 1]){
                                for(int h: fre[j]){
                                        for(int z: A[j][h]){
                                                d[j | (1 << z)][z] += d[j][h];
                                        }
                                }
                        }
                }

                solve(mask | (g << cur), cur + 1);

                if(g == 0){
                        for(int j: v[cur + 1]){
                                for(int h: fre[j]){
                                        for(int z: B[j][h]){
                                                d[j | (1 << z)][z] -= d[j][h];
                                        }
                                }
                        }
                } else{
                        for(int j: v[cur + 1]){
                                for(int h: fre[j]){
                                        for(int z: A[j][h]){
                                                d[j | (1 << z)][z] -= d[j][h];
                                        }
                                }
                        }
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        //n = 14;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        char c;
                        cin >> c;
                        //c = '0';
                        if(c == '1'){
                                a[i] += (1 << j);
                                ::c[i][j] = 1;

                        }
                }
        }
        all = (1 << n);

        for(int i = 0; i < n; i++) d[1 << i][i] = 1;

        for(int i = 0; i < all; i++){
                l[i] = __builtin_popcount(i);
                v[l[i]].push_back(i);
                for(int j = 0; j < n; j++){
                        if(i & (1 << j)) fre[i].push_back(j);
                }

                for(int j: fre[i]){
                        for(int h = 0; h < n; h++){
                                if(j == h || i & (1 << h)) continue;
                                if(c[j][h]) A[i][j].push_back(h);
                                else B[i][j].push_back(h);
                        }
                }
        }

        solve(0, 0);

        for(int i = 0; i < (1 << n - 1); i++) cout << res[i] << " ";
}