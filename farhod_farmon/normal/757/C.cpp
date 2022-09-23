#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100010;
const long long mod = 1e9 + 7;

using namespace std;

int q = 100109;
int p = 100103;

int n;
int m;
int c[N * 10];
int po[N];
int fo[N];
pair < int, int > hsh[N * 10];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        po[0] = p;
        fo[0] = q;
        for(int i = 1; i < N; i++){
                po[i] = 1ll * po[i - 1] * p % mod;
                fo[i] = 1ll * fo[i - 1] * q % mod;
        }
        for(int i = 1; i <= n; i++){
                int l;
                cin >> l;
                vector < int > g(l);
                vector < pair < int, int > > v;
                for(int j = 0; j < l; j++){
                        cin >> g[j];
                        c[g[j]]++;
                }
                for(int j = 0; j < l; j++){
                        if(c[g[j]]){
                                v.push_back({c[g[j]], g[j]});
                                c[g[j]] = 0;
                        }
                }
                sort(v.begin(), v.end());
                for(int j = 0, C = 1; j < v.size(); j++){
                        if(j > 0 && v[j].fi != v[j - 1].fi){
                                C++;
                        }
                        int x = v[j].se;
                        hsh[x].fi += 1ll * C * po[i] % mod;
                        if(hsh[x].fi >= mod){
                                hsh[x].fi -= mod;
                        }
                        hsh[x].se += 1ll * C * fo[i] % mod;
                        if(hsh[x].se >= mod){
                                hsh[x].se -= mod;
                        }
                }
        }
        vector < pair < int, int > > v;
        for(int i = 1; i <= m; i++){
                v.push_back(hsh[i]);
        }
        sort(v.begin(), v.end());
        int ans = 1;
        for(int i = 0, c = 1, f = 1; i < v.size(); i++){
                if(i + 1 < v.size() && v[i] == v[i + 1]){
                        c++;
                        f = 1ll * f * c % mod;
                        continue;
                }
                ans = 1ll * ans * f % mod;
                c = f = 1;
        }
        cout << ans << "\n";
}