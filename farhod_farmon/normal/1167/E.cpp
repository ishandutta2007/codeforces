#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int b[N];
int f[N];

void upd(int x, int g)
{
        x += 2;
        while(x < N){
                f[x] += g;
                x += x & -x;
        }
}

int get(int x)
{
        x += 2;
        int res = 0;
        while(x > 0){
                res += f[x];
                x -= x & -x;
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("sum.in", "r", stdin);
        //freopen("sum.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                if(a[x] == 0){
                        a[x] = i;
                }
                b[x] = i;
        }
        vector < int > l(m + 2), r(m + 2);
        l[0] = 0;
        r[m + 1] = n + 1;
        for(int i = 1; i <= m; i++){
                l[i] = l[i - 1];
                if(l[i] == -1 || !a[i]){
                        continue;
                }
                if(a[i] < l[i]){
                        l[i] = -1;
                } else{
                        l[i] = b[i];
                }
        }
        for(int i = m; i >= 1; i--){
                r[i] = r[i + 1];
                if(r[i] == -1 || !a[i]){
                        continue;
                }
                if(b[i] > r[i]){
                        r[i] = -1;
                } else{
                        r[i] = a[i];
                }
        }
        long long res = 0, all = 0;
        for(int i = m + 1; i >= 2; i--){
                if(r[i] == -1){
                        break;
                }
                all += 1;
                upd(r[i], 1);
        }
        for(int i = 0; i < m; i++){
                if(l[i] == -1){
                        break;
                }
                res += all - get(l[i] - 1);
                if(r[i + 2] != -1){
                        all -= 1;
                        upd(r[i + 2], -1);
                }
        }
        cout << res << "\n";
}