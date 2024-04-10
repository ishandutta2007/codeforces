#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define fi first
#define se second

const int N = 250;
const int Q = 1000100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int col[N];
char c[N][N];
bitset < N > f[N + N + 2];
bitset < N > pol[N][N];
bitset < N > mask[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        //freopen("nodes.in","r",stdin);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        cin >> c[i][j];
                        c[i][j] -= 'a';
                }
        }
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        for(int h = 0; h < 26; h++){
                                col[h] = 0;
                        }
                        int bad = 0;
                        for(int h = j; h < m; h++){
                                bad -= col[c[i][h]] & 1;
                                col[c[i][h]]++;
                                bad += col[c[i][h]] & 1;
                                if(bad < 2){
                                        pol[i][j][h] = 1;
                                }
                        }
                }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
                for(pair < int, int > p: {make_pair(i, i), make_pair(i - 1, i)}){
                        for(int j = 0; j < m; j++){
                                mask[j].reset();
                                mask[j].flip();
                        }
                        int l = p.fi, r = p.se;
                        while(l >= 0 && r < n){
                                for(int j = 0; j < m; j++){
                                        mask[j] &= pol[l][j];
                                }
                                for(int g = 0; g < 26; g++){
                                        int s = 0;
                                        for(int j = m - 1; j >= 0; j--){
                                                f[s + N][j] = 1;
                                                s += c[l][j] == g;
                                                s -= c[r][j] == g;
                                                mask[j] &= f[s + N];
                                        }
                                        s = 0;
                                        for(int j = m - 1; j >= 0; j--){
                                                f[s + N][j] = 0;
                                                s += c[l][j] == g;
                                                s -= c[r][j] == g;
                                        }
                                }
                                for(int j = 0; j < m; j++){
                                        ans += mask[j].count();
                                }
                                l--;
                                r++;
                        }
                }
        }
        cout << ans << "\n";
}