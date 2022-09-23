#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int l[N];
int r[N];
map < int, int > d, f;

int go_r(int x, int i)
{
        if(d.find(x - i) != d.end()){
                return r[d[x - i]];
        }
        return min(x + (m - i + 1), n);
}

int go_l(int x, int i)
{
        if(f.find(x + i) != f.end()){
                return l[f[x + i]];
        }
        return max(1, x - (m - i + 1));
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                cin >> a[i];
        }
        if(n == 1){
                cout << 0 << "\n";
                return 0;
        }

        for(int i = m; i >= 1; i--){
                r[i] = go_r(a[i] - 1, i);
                l[i] = go_l(a[i] + 1, i);

                d[a[i] - i] = i;
                f[a[i] + i] = i;
        }

        long long res = 0;
        for(int i = 1; i <= n; i++){
                res += go_r(i, 0) - i + 1;
                res += i - go_l(i, 0) + 1;
                res -= 1;
        }

        cout << res << "\n";
}