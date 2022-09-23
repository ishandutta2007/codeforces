#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3030;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int res[N];
int d[N];
bool good[N][N];
long long p[N];
long long p2[N];
long long mod2 = 1e9 + 9;

void add(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
        else if(x < 0){
                x += mod;
        }
}

void add2(int &x, int y)
{
        x += y;
        if(x >= mod2){
                x -= mod2;
        }
        else if(x < 0){
                x += mod2;
        }
}

void solve(int s)
{
        for(int i = 0; i <= n; i++){
                d[i] = 0;
        }
        d[s] = 1;
        string t = "";
        for(int i = s + 1; i <= n; i++){
                t = "";
                for(int j = 0; j < 4; j++){
                        if(i - j == s){
                                break;
                        }
                        t += char(a[i - 1 - j] + '0' - 1);
                        if(j == 3){
                                swap(t[0], t[3]);
                                swap(t[1], t[2]);
                                if(t == "0011" || t == "0101" || t == "1110" || t == "1111"){
                                        break;
                                }
                        }
                        add(d[i], d[i - j - 1]);
                }
                if(good[s][i - 1]){
                        add(res[i - 1], d[i]);
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> a[i];
                a[i] += 1;
        }
        p[0] = 1;
        p2[0] = 1;
        for(int i = 1; i < N; i++){
                p[i] = p[i - 1] * 3 % mod;
                p2[i] = p2[i - 1] * 5 % mod2;
        }
        for(int i = 1; i <= n; i++){
                vector < pair < pair < int, int >, int > > v;
                int hsh = 0;
                int hsh2 = 0;
                for(int j = 0; j < i; j++){
                        add(hsh, 1ll * p[j] * a[j] % mod);
                        add2(hsh2, 1ll * p2[j] * a[j] % mod2);
                }
                for(int j = 0; j + i - 1 < n; j++){
                        v.push_back({{1ll * hsh * p[n - j] % mod, 1ll * hsh2 * p2[n - j] % mod2}, j});
                        if(j + i < n){
                                add(hsh, - 1ll * p[j] * a[j] % mod);
                                add(hsh, 1ll * p[j + i] * a[j + i] % mod);
                                add2(hsh2, - 1ll * p2[j] * a[j] % mod2);
                                add2(hsh2, 1ll * p2[j + i] * a[j + i] % mod2);
                        }
                }
                sort(v.begin(), v.end());
                for(int j = 0; j < v.size(); j++){
                        if(j > 0 && v[j].fi == v[j - 1].fi){
                                continue;
                        }
                        good[v[j].se][v[j].se + i - 1] = 1;
                }
        }
        for(int i = 0; i < n; i++){
                solve(i);
        }
        for(int i = 0; i < n; i++){
                add(res[i + 1], res[i]);
                cout << res[i] << "\n";
        }
}