#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100010;
const long long Q = 10001;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

int n;
int a[N];

map < vector < int >, pair < int, pair < int, int > > > d;
map < vector < int >, int > f;

vector < pair < int, pair < int, int > > > slow()
{
        vector < pair < int, pair < int, int > > > g;
        vector < int > v;
        for(int i = 1; i <= n; i++){
                v.push_back(a[i]);
        }
        d[v] = {0, {0, 0}};
        queue < vector < int > > q;
        q.push(v);
        while(!q.empty()){
                v = q.front();
                q.pop();
                int cur = f[v];
                for(int i = 0; i < v.size(); i++){
                        for(int j = i + 1; j < v.size(); j++){
                                int h = j + j - i;
                                if(h < v.size()){
                                        v[i] ^= 1; v[j] ^= 1; v[h] ^= 1;
                                        if(d.find(v) == d.end()){
                                                d[v] = {i, {j, h}};
                                                f[v] = cur + 1;
                                                q.push(v);
                                        }
                                        v[i] ^= 1; v[j] ^= 1; v[h] ^= 1;
                                }
                        }
                }
        }
        for(int i = 0; i < v.size(); i++){
                v[i] = 0;
        }
        if(d.find(v) == d.end()){
                return {{-1, {-1, -1}}};
        }
        for(int i = f[v]; i; i--){
                auto p = d[v];
                g.push_back(p);
                v[p.fi] ^= 1;
                v[p.se.fi] ^= 1;
                v[p.se.se] ^= 1;
        }
        return g;
}

void upd(vector < pair < int, pair < int, int > > > &v, int a, int b, int c)
{
        v.push_back({a, {b, c}});
        ::a[a] ^= 1;
        ::a[b] ^= 1;
        ::a[c] ^= 1;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int last = -1;
        vector < pair < int, pair < int, int > > > v, g;
        int suka = 0;
        for(int i = 1; i <= n; i += 3){
                if(i + 12 <= n){
                        vector < int > t;
                        if(a[i])t.push_back(i);
                        if(a[i + 1])t.push_back(i + 1);
                        if(a[i + 2])t.push_back(i + 2);
                        if(t.size() == 0){
                                continue;
                        }
                        else if(t.size() == 3){
                                upd(v, i, i + 1, i + 2);
                                continue;
                        }
                        if(t.size() == 2 && t[1] == i + 1){
                                if(last == -1){
                                        last = i;
                                        continue;
                                }
                                if(i + 1 + i + 1 - last - 1 <= n){
                                        int h = i + i - last;
                                        upd(v, last, i, h);
                                        upd(v, last + 1, i + 1, h + 1);
                                        last = -1;
                                }
                                else{
                                        suka++;
                                        int j = (n + last - 1) / 2;
                                        int h = j + j - last;
                                        upd(v, last, j, h);
                                        upd(v, last + 1, j, h - 1);
                                        last = i;
                                 }
                        }
                        else{
                                int j = i + 3;
                                if(t.size() == 2){
                                        j = t[1];
                                }
                                upd(v, t[0], j, j + j - t[0]);
                        }
                }
                else{
                        if(last != -1){
                                int j = (n + last - 1) / 2;
                                int h = j + j - last;
                                upd(v, last, j, h);
                                upd(v, last + 1, j, h - 1);
                                suka++;
                        }
                        int m = n - i + 1;
                        for(int j = 1; j <= m; j++){
                                a[j] = a[j + i - 1];
                        }
                        n = m;
                        g = slow();
                        if(g.size() > 0 && g[0].fi == -1){
                                cout << "NO" << "\n";
                                return;
                        }
                        assert(suka <= 10);
                        cout << "YES" << "\n";
                        cout << v.size() + g.size() << "\n";
                        for(auto p: v){
                                cout << p.fi << " " << p.se.fi << " " << p.se.se << "\n";
                        }
                        for(auto p: g){
                                cout << p.fi + i << " " << p.se.fi + i << " " << p.se.se + i << "\n";
                        }
                        return;
                }
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("distance.in");
        //fout("distance.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}