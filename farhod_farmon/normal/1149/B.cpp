#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int q;
int c[N];
int d[254][254][254];
int f[N][27];
vector < int > v[4];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                char x;
                cin >> x;
                c[i] = x - 'a';
        }
        for(int i = 0; i < N; i++){
                for(int j = 0; j < 27; j++){
                        f[i][j] = n + 1;
                }
        }
        int a[4] = {0, 0, 0, 0};
        int st[4] = {0, 0, 0, 0};
        for(int i = n; i >= 1; i--){
                for(int j = 0; j < 26; j++){
                        f[i][j] = f[i + 1][j];
                }
                f[i][c[i]] = i;
        }
        for(int i = 0; i < 254; i++){
                for(int j = 0; j < 254; j++){
                        for(int h = 0; h < 254; h++){
                                d[i][j][h] = n + 1;
                        }
                }
        }
        d[0][0][0] = 0;
        for(int it = 1; it <= q; it++){
                char tp, y;
                int x;
                cin >> tp >> x;
                if(tp == '+'){
                        cin >> y;
                        a[x] += 1;
                        v[x].push_back(y - 'a');
                        d[a[1]][a[2]][a[3]] = n + 1;

                        st[1] = st[2] = st[3] = 0;
                        st[x] = max(0, a[x] - 10);

                        for(int i = st[1]; i <= a[1]; i++){
                                for(int j = st[2]; j <= a[2]; j++){
                                        for(int h = st[3]; h <= a[3]; h++){
                                                int cur = d[i][j][h];
                                                if(i + 1 <= a[1])d[i + 1][j][h] = min(d[i + 1][j][h], f[cur + 1][v[1][i]]);
                                                if(j + 1 <= a[2])d[i][j + 1][h] = min(d[i][j + 1][h], f[cur + 1][v[2][j]]);
                                                if(h + 1 <= a[3])d[i][j][h + 1] = min(d[i][j][h + 1], f[cur + 1][v[3][h]]);
                                        }
                                }
                        }
                } else{
                        st[1] = st[2] = st[3] = 0;
                        st[x] = a[x];
                        for(int i = st[1]; i <= a[1]; i++){
                                for(int j = st[2]; j <= a[2]; j++){
                                        for(int h = st[3]; h <= a[3]; h++){
                                                d[i][j][h] = n + 1;
                                        }
                                }
                        }
                        a[x] -= 1;
                        v[x].pop_back();
                }

                if(d[a[1]][a[2]][a[3]] <= n){
                        cout << "YES" << "\n";
                } else{
                        cout << "NO" << "\n";
                }
        }
}