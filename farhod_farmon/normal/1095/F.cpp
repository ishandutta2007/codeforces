#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int m;
int p[N];
long long a[N];
set < pair < long long, int > > s;
vector < pair < long long, pair < int, int > > > e;

int get(int x)
{
        return x == p[x] ? x : p[x] = get(p[x]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                p[i] = i;
                long long x;
                cin >> x;
                a[i] = x;
                s.insert({x, i});
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                long long w;
                cin >> x >> y >> w;
                e.push_back({w, {x, y}});
        }
        long long res = 0;
        sort(e.begin(), e.end());
        e.push_back({1e13, {1, 1}});
        for(auto cur: e){
                while(s.size() > 1){
                        int x = s.begin()->se;
                        s.erase(s.begin());
                        int y = s.begin()->se;
                        s.erase(s.begin());
                        if(a[x] + a[y] > cur.fi){
                                s.insert({a[x], x});
                                s.insert({a[y], y});
                                break;
                        }
                        res += a[x] + a[y];
                        if(a[x] > a[y]){
                                swap(x, y);
                        }
                        p[y] = x;
                        s.insert({a[x], x});
                }
                int x = cur.se.fi, y = cur.se.se;
                long long w = cur.fi;
                x = get(x);
                y = get(y);
                if(x != y){
                        res += w;
                        s.erase({a[x], x});
                        s.erase({a[y], y});
                        if(a[x] > a[y]){
                                swap(x, y);
                        }
                        p[y] = x;
                        s.insert({a[x], x});
                }
        }
        cout << res << "\n";
}