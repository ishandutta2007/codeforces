#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 550;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

int n;
int st[N];
long long a[N];
vector < pair < long long, int > > v;

long long get3(long long x)
{
        long long l = 1, r = 2e9;
        while(l < r){
                long long m = (l + r) / 2;
                if(m * m < x){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        if(l * l == x){
                return l;
        }
        return -1;
}

long long get5(long long x)
{
        x = get3(x);
        if(x == -1){
                return -1;
        }
        x = get3(x);
        if(x == -1){
                return -1;
        }
        return x;
}

long long get4(long long x)
{
        long long l = 1, r = 1500000;
        while(l < r){
                long long m = (l + r) / 2;
                if(m * m * m < x){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        if(l * l * l == x){
                return l;
        }
        return -1;
}

bool ok(long long x)
{
        for(long long i = 2; i * i <= x; i++){
                if(x % i == 0){
                        return false;
                }
        }
        return true;
}

void add(long long x, int g)
{
        for(int i = 0; i < v.size(); i++){
                if(v[i].fi == x){
                        v[i].se += g;
                        return;
                }
        }
        v.push_back({x, g});
}

void upd()
{
        for(int i = 1; i <= n; i++){
                if(a[i] == 1){
                        continue;
                }
                while(st[i] < v.size()){
                        int j = st[i];
                        if(a[i] % v[j].fi == 0){
                                add(a[i] / v[j].fi, 1);
                                add(v[j].fi, 1);
                                a[i] = 1;
                                upd();
                                break;
                        }
                        else{
                                st[i]++;
                        }
                }
        }
}

map < long long, int > f;

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                long long p = get5(a[i]);
                if(p != -1 && ok(p)){
                        a[i] = 1;
                        add(p, 4);
                        continue;
                }
                p = get4(a[i]);
                if(p != -1 && ok(p)){
                        a[i] = 1;
                        add(p, 3);
                        continue;
                }
                p = get3(a[i]);
                if(p != -1 && ok(p)){
                        a[i] = 1;
                        add(p, 2);
                        continue;
                }
        }
        upd();
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(i == j || a[i] == 1 || a[j] == 1){
                                continue;
                        }
                        long long g = __gcd(a[i], a[j]);
                        if(g > 1 && g != a[i]){
                                add(a[i] / g, 1);
                                add(a[j] / g, 1);
                                add(g, 2);
                                a[i] = a[j] = 1;
                                upd();
                        }
                }
        }
        long long ans = 1;
        for(int i = 1; i <= n; i++){
                if(a[i] > 1){
                        f[a[i]]++;
                }
        }
        for(auto p: f){
                ans = (ans * (p.se + 1) * (p.se + 1)) % mod;
        }
        for(auto p: v){
                ans = (ans * (p.se + 1)) % mod;
        }
        cout << ans << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}