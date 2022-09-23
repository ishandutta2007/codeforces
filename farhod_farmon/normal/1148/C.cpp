#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int MAGIC = 1000;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
int f[N];
vector < pair < int, int > > res;

void upd(int x, int y)
{
        if(x == y){
                return;
        }
        assert(abs(x - y) >= n / 2);
        res.push_back({x, y});
        swap(f[a[x]], f[a[y]]);
        swap(a[x], a[y]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                f[a[i]] = i;
        }
        int h = n / 2 + 1;
        for(int i = 1; i <= n / 2; i++){
                while(h <= n && a[h] <= n / 2){
                        h += 1;
                }
                if(h > n || f[i] <= h){
                        continue;
                }
                upd(1, f[i]);
                upd(1, h);
        }
        for(int i = 1; i <= n / 2; i++){
                while(h <= n && a[h] <= n / 2){
                        h += 1;
                }
                if(a[i] <= n / 2){
                        assert(h <= n);
                        upd(i, h);
                }
        }
        for(int i = 1; i <= n / 2; i++){
                if(f[i] == n / 2 + i){
                        continue;
                }
                int g = f[i];
                upd(1, g);
                upd(1, n / 2 + i);
                upd(1, g);
        }
        for(int i = n / 2 + 1; i <= n; i++){
                if(f[i] == i - n / 2){
                        continue;
                }
                int g = f[i];
                upd(n, g);
                upd(n, i - n / 2);
                upd(n, g);
        }
        for(int i = 1; i <= n / 2; i++){
                upd(i, i + n / 2);
        }
        cout << res.size() << "\n";
        assert(res.size() <= 4 * n + n / 2);
        for(auto p: res){
                cout << p.fi << " " << p.se << "\n";
        }
        for(int i = 2; i <= n; i++){
                assert(a[i - 1] < a[i]);
        }
}