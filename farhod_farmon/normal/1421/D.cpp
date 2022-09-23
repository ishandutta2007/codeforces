#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 6;

using namespace std;

long long c[N];
vector < pair < int, int > > v = {{1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, 0}};

int si(int x)
{
        return (x > 0 ? 1 : x < 0 ? -1 : 0);
}

void solve()
{
        int x, y;
        cin >> x >> y;
        map < pair < int, int >, int > id;
        for(int i = 0; i < 6; i++){
                cin >> c[i];
                id[v[i]] = i;
        }
        pair < int, int > nx;
        for(int it = 0; it < 6; it++){
                for(int i = 0; i < 6; i++){
                        for(int j = 0; j < 6; j++){
                                nx = v[i];
                                nx.fi += v[j].fi;
                                nx.se += v[j].se;
                                if(id.find(nx) != id.end()){
                                        c[id[nx]] = min(c[id[nx]], c[i] + c[j]);
                                }
                        }
                }
        }
        long long res = 0;
        for(int it = 0; it < 2; it++){
                for(int i = 0; i < 6; i++){
                        if(si(x) == v[i].fi && si(y) == v[i].se){
                                int g = 1e9;
                                //cout << i << endl;
                                if(x) g = min(g, abs(x));
                                if(y) g = min(g, abs(y));

                                res += c[i] * g;
                                x -= g * v[i].fi;
                                y -= g * v[i].se;
                        }
                }
        }
        for(int it = 0; it < 2; it++){
                for(int i = 0; i < 6; i++){
                        if((si(x) == v[i].fi && !v[i].se) || (si(y) == v[i].se && !v[i].fi)){
                                int g = 1e9;
                                //cout << i << endl;
                                if(v[i].fi) g = min(g, abs(x));
                                if(v[i].se) g = min(g, abs(y));

                                res += c[i] * g;
                                x -= g * v[i].fi;
                                y -= g * v[i].se;
                        }
                }
        }
        assert(x == 0 && y == 0);

        cout << res << "\n";
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}