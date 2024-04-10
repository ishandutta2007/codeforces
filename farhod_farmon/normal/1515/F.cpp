#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
int m;
int A;
int p[N];
int s[N];
long long a[N];
vector < pair < int, int > > v[N];

int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> A;
        set < pair < long long, int > > S;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                p[i] = i;
                s[i] = 1;
                S.insert({a[i], i});
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back({y, i});
                v[y].push_back({x, i});
        }
        vector < int > res;

        while(!S.empty()){
                int x = (--S.end())->se;
                S.erase(--S.end());

                while(!v[x].empty()){
                        auto g = v[x].back();
                        v[x].pop_back();

                        int y = get(g.fi);
                        if(x == y || a[x] + a[y] < A){
                                continue;
                        }

                        res.push_back(g.se);
                        S.erase({a[y], y});

                        if(s[x] < s[y]){
                                swap(x, y);
                        }


                        a[x] += a[y] - A;
                        s[x] += s[y];
                        p[y] = x;
                        for(auto p: v[y]){
                                v[x].push_back(p);
                        }
                        v[y].clear();

                        S.insert({a[x], x});
                        break;
                }
        }
        if(res.size() != n - 1){
                cout << "NO" << "\n";
                return 0;
        }
        cout << "YES" << "\n";
        for(int x: res){
                cout << x << "\n";
        }
}