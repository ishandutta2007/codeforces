#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 5050;

using namespace std;

map < int, bool > pl;
map < int, int > hsh;
int n, m, a[N], g[N];

int F(int x)
{
    if(x == 1)
        return 0;
    int cc = x;
    if(hsh.find(x) != hsh.end())
        return hsh[x];
    int cnt = 0;
    for(int i = 2; i * i <= x; i++){
        while(x % i == 0){
            x /= i;
            if(pl.find(i) == pl.end())
                cnt++;
            else
                cnt--;
        }
    }
    if(x != 1){
        if(pl.find(x) == pl.end())
            cnt++;
        else
            cnt--;
    }
    hsh[cc] = cnt;
    return cnt;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        pl[x] = true;
    }
    bool f = true;
    while(f){
        f = false;
        g[1] = a[1];
        for(int i = 2; i <= n; i++)
            g[i] = __gcd(g[i - 1], a[i]);
        for(int i = n; i >= 1; i--){
            if(F(g[i]) < 0){
                f = true;
                for(int j = 1; j <= i; j++)
                    a[j] /= g[i];
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += F(a[i]);
    cout << ans << endl;
}