#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 50500;

using namespace std;

int n;
int a[N];
int b[N];
int c[N];
bool dead[N];
vector < pair < int, int > > res;

void add(int x, int y)
{
        res.push_back({x, y});
        dead[x] = dead[y] = true;
}

void solve(vector < int > v)
{
        map < int, vector < pair < int, int > > > g;
        for(int x: v){
                g[b[x]].push_back({c[x], x});
        }
        for(auto p: g){
                auto shit = p.se;
                sort(shit.begin(), shit.end());
                while(shit.size() > 1){
                        int x = shit.back().se;
                        shit.pop_back();
                        int y = shit.back().se;
                        shit.pop_back();

                        add(x, y);
                }
        }
        vector < pair < int, int > > nv;
        for(int x: v){
                if(!dead[x]){
                        nv.push_back({b[x], x});
                }
        }
        sort(nv.begin(), nv.end());
        while(nv.size() > 1){
                int x = nv.back().se;
                nv.pop_back();
                int y = nv.back().se;
                nv.pop_back();

                add(x, y);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        map < int, vector < int > > v;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i] >> c[i];
                v[a[i]].push_back(i);
        }
        for(auto p: v){
                if(p.se.size() > 1){
                        solve(p.se);
                }
        }
        vector < pair < int, int > > nv;
        for(int i = 1; i <= n; i++){
                if(!dead[i]){
                        nv.push_back({a[i], i});
                }
        }
        sort(nv.begin(), nv.end());
        for(int i = 0; i < nv.size(); i += 2){
                res.push_back({nv[i].se, nv[i + 1].se});
        }
        for(auto p: res){
                cout << p.fi << " " << p.se << "\n";
        }
}