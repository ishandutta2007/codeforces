#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const int MAGIC = 777;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int n;

int C;
int dist[N][N];
vector < int > edge[N];
bool off = false;
string query(vector < int > v)
{
        assert((int)v.size() == n);
        C += 1;
        if(C > 80){
                cout << "Too many queries" << "\n";
                exit(0);
        }
        string res = "";
        if(off){
                for(int i = 0; i < n; i++){
                        bool good = false;
                        for(int j = 0; j < n; j++){
                                if(i != j){
                                        good |= dist[i][j] <= v[j];
                                }
                        }
                        res += char(good + '0');
                }
        } else{
                cout << "?";
                for(int i = 0; i < n; i++){
                        cout << " " << min(v[i], n - 1);
                }
                cout << endl;
                cin >> res;
        }
        for(int i = 0; i < n; i++){
                res[i] -= '0';
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        if(off){
                for(int i = 1; i < n; i++){
                        int x, y;
                        cin >> x >> y;
                        x -= 1;
                        y -= 1;
                        edge[x].push_back(y);
                        edge[y].push_back(x);
                }
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < n; j++){
                                dist[i][j] = 1e9;
                        }
                        dist[i][i] = 0;
                        queue < int > q;
                        q.push(i);
                        while(!q.empty()){
                                int x = q.front();
                                q.pop();
                                for(int y: edge[x]){
                                        if(dist[i][x] + 1 < dist[i][y]){
                                                dist[i][y] = dist[i][x] + 1;
                                                q.push(y);
                                        }
                                }
                        }
                }
        }

        vector < pair < pair < int, int >, vector < int > > > v;
        v.push_back({{0, 0}, {0}});
        v.push_back({{1, n - 1}, {}});
        for(int i = 1; i < n; i++){
                v.back().se.push_back(i);
        }

        while(true){
                vector < pair < pair < int, int >, vector < int > > > nv;
                bool done = true;
                for(int i = 0; i < v.size(); i++){
                        if(v[i].fi.fi == v[i].fi.se){
                                nv.push_back(v[i]);
                        }
                }
                for(int it: {0, 1}){
                        vector < int > g1(n, 0), g2(n, 0);
                        bool now = 0;
                        for(int i = 0; i < v.size(); i++){
                                if(v[i].fi.fi == v[i].fi.se || v[i].se.empty()){
                                        continue;
                                }
                                now ^= 1;
                                if(now != it){
                                        continue;
                                }
                                done = false;
                                int l = v[i].fi.fi, r = v[i].fi.se, m = (l + r) / 2;
                                for(int x: v[i - 1].se){
                                        g1[x] = m - l + 1;
                                }
                                for(int x: v[i - 1].se){
                                        g2[x] = m - l;
                                }
                        }
                        now = 0;
                        string s = query(g1);
                        string t = query(g2);
                        for(int i = 0; i < v.size(); i++){
                                if(v[i].fi.fi == v[i].fi.se || v[i].se.empty()){
                                        continue;
                                }
                                now ^= 1;
                                if(now != it){
                                        continue;
                                }
                                vector < int > a, b, c;
                                int l = v[i].fi.fi, r = v[i].fi.se, m = (l + r) / 2;
                                for(int x: v[i].se){
                                        if(s[x] && !t[x]){
                                                b.push_back(x);
                                        } else if(s[x]){
                                                a.push_back(x);
                                        } else{
                                                assert(!t[x]);
                                                c.push_back(x);
                                        }
                                }
                                if(!a.empty()) nv.push_back({{l, m - 1}, a});
                                if(!b.empty()) nv.push_back({{m, m}, b});
                                if(!c.empty()) nv.push_back({{m + 1, r}, c});
                        }
                }
                v = nv;
                sort(v.begin(), v.end());
                if(done){
                        break;
                }
        }

        /*for(int i = 0; i < v.size(); i++){
                cout << v[i].fi.fi << " " << v[i].fi.se << ": ";
                for(int x: v[i].se){
                        cout << x + 1 << ' ';
                }
                cout << endl;
        }*/
        /*for(int i = 1; i < v.size(); i++){
                if(v[i].se.empty()){
                        break;
                }
                assert(v[i - 1].fi.fi + 1 == v[i].fi.fi);
                assert(v[i - 1].fi.fi + 1 == v[i].fi.se);
        }*/
        vector < int > res(n, 0);
        for(int it = 0; it < 3; it++){
                for(int i = 0; (1 << i) < n; i++){
                        vector < int > g(n, 0);
                        for(int j = it; j < (int)v.size(); j += 3){
                                for(int x: v[j].se){
                                        g[x] = (x >> i) & 1;
                                }
                        }
                        string s = query(g);
                        for(int j = it + 1; j < (int)v.size(); j += 3){
                                for(int x: v[j].se){
                                        if(s[x]){
                                                res[x] |= (1 << i);
                                        }
                                }
                        }
                }
        }
        cout << "!" << endl;
        for(int i = 1; i < n; i++){
                cout << res[i] + 1 << " " << i + 1 << endl;
        }
}