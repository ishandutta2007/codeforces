#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const int mod = 1e9 + 7;

using namespace std;

int n;
int x[N];
int y[N];
int c[N];
int k[N];
int p[N];

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> x[i] >> y[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> c[i];
        }
        long long res = 0;
        for(int i = 1; i <= n; i++){
                cin >> k[i];

                p[i] = i;
                res += c[i];
        }
        vector < pair < long long, pair < int, int > > > e;
        for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                        e.push_back({(abs(x[i] - x[j]) + abs(y[i] - y[j])) * 1ll * (k[i] + k[j]), {i, j}});
                }
        }
        sort(e.begin(), e.end());
        vector < pair < int, int > > ee;
        for(auto E: e){
                long long cost = E.fi;
                int x = E.se.fi, y = E.se.se;
                x = get(x);
                y = get(y);
                if(x == y){
                        continue;
                }
                if(c[x] > c[y]){
                        swap(x, y);
                }
                if(cost < c[y]){
                        res += cost - c[y];
                        p[y] = x;
                        ee.push_back(E.se);
                }
        }
        cout << res << "\n";
        vector < int > ne;
        for(int i = 1; i <= n; i++){
                if(get(i) == i){
                        ne.push_back(i);
                }
        }
        cout << ne.size() << "\n";
        for(int x: ne){
                cout << x << " ";
        }
        cout << "\n";
        cout << ee.size() << "\n";
        for(auto p: ee){
                cout << p.fi << " " << p.se << "\n";
        }
}