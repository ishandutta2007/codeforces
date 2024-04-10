#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int a[N];
int p[N];
map < pair < int, int >, int > used;

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

int c[N];

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                for(int j = 1; j <= n; j++){
                        cin >> a[j];
                        if(j > 1){
                                used[{a[j - 1], a[j]}]++;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                p[i] = i;
        }
        while(!used.empty()){
                auto x = *used.begin();
                used.erase(used.begin());
                if(x.se == m){
                        if(get(x.fi.fi) != get(x.fi.se)){
                                p[get(x.fi.fi)] = get(x.fi.se);
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                c[get(i)]++;
        }
        long long ans = 0;
        for(int i = 1; i <= n; i++){
                ans += 1ll * c[i] * (c[i] + 1) / 2;
        }
        cout << ans << "\n";
}//