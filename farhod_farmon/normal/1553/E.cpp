#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int mod = 31607;

using namespace std;

int n;
int m;
int a[N];
int c[N];
int p[N];

int get(int x) { return p[x] == x ? x : get(p[x]); }

int solve(int g)
{
        for(int i = 0; i < n; i++){
                p[i] = i;
        }
        int res = 0;
        for(int i = 0; i < n; i++){
                int x = get(i), y = get((a[i] + g) % n);

                if(x != y){
                        p[x] = y;
                        res += 1;
                }
        }
        return res;
}

void solve()
{
        cin >> n >> m;

        for(int i = 0; i < n; i++){
                c[i] = 0;
        }

        for(int i = 0; i < n; i++){
                cin >> a[i];
                a[i] -= 1;

                int g = i - a[i];
                if(g < 0){
                        g += n;
                }
                c[g] += 1;
        }

        vector < int > res;
        for(int i = 0; i < n; i++){
                if(c[i] >= n / 3 && solve(i) <= m){
                        res.push_back(i);
                }
        }
        cout << res.size();
        for(int x: res){
                cout << " " << x;
        }
        cout << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}