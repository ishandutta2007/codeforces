#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
const int m1 = 1e9 + 3;

using namespace std;

int n;
int m;
int a[N];
int d[N][N * N];
int f[N][N * N];

void add(int x)
{
        for(int i = n; i >= 1; i--){
                for(int j = x; j <= m; j++){
                        d[i][j] += d[i - 1][j - x];
                        if(d[i][j] >= m1){
                                d[i][j] -= m1;
                        }
                }
        }
}

void del(int x)
{
        for(int i = 1; i <= n; i++){
                for(int j = x; j <= m; j++){
                        d[i][j] -= d[i - 1][j - x];
                        if(d[i][j] < 0){
                                d[i][j] += m1;
                        }
                }
        }
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        set < int > s;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                a[x]++;
                s.insert(x);
        }
        if(s.size() <= 2){
                cout << n << "\n";
                return 0;
        }
        m = 100 * n;
        d[0][0] = 1;
        f[0][0] = 1;
        for(int i = 1; i <= 100; i++){
                for(int j = 0; j < a[i]; j++){
                        add(i);
                }
        }
        int ans = 0;
        for(int i = 1; i <= 100; i++){
                for(int j = 0; j < a[i]; j++){
                        del(i);
                }
                for(int j = 1; j <= a[i]; j++){
                        bool good = true;
                        int all = i * j;
                        for(int h = 0; h < j; h++){
                                if(d[j - h][all]){
                                        good = false;
                                }
                                all -= i;
                        }
                        if(good){
                                ans = max(ans, j);
                        }
                }
                for(int j = 0; j < a[i]; j++){
                        add(i);
                }
        }
        cout << ans << "\n";
}