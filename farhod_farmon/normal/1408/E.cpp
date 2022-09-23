#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n, m;
int a[N], b[N];
int p[N];

int get(int x) { return x == p[x] ? x : p[x] = get(p[x]); }

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= m; i++) cin >> b[i];
        vector < pair < int, pair < int, int > > > e;
        long long all = 0;
        for(int i = 1; i <= n; i++){
                int s;
                cin >> s;
                for(int j = 1; j <= s; j++){
                        int x;
                        cin >> x;
                        all += a[i] + b[x];
                        e.push_back({a[i] + b[x], {i, n + x}});
                }
        }
        for(int i = 1; i <= n + m; i++) p[i] = i;
        sort(e.begin(), e.end());
        reverse(e.begin(), e.end());
        for(auto p: e){
                int x = p.se.fi, y = p.se.se;
                x = get(x);
                y = get(y);
                if(x != y){
                        ::p[x] = y;
                        all -= p.fi;
                }
        }
        cout << all << "\n";
}