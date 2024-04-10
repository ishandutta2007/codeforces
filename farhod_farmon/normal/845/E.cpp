#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 3020;
const long long Q = 2e18;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int m;
int k;
int a[N];
int b[N];
int l[N];
int r[N];
int d[N];

map < int, int > id;

pair < int, int > get(int t)
{
        int ax = -1, ay = -1;
        int G = 1;
        vector < int > v;
        vector < pair < int, int > > ord;
        for(int i = 1; i <= k; i++){
                l[i] = max(1, a[i] - t);
                r[i] = min(n, a[i] + t);
                v.push_back(max(1, l[i] - 1));
                v.push_back(l[i]);
                v.push_back(r[i]);
                v.push_back(min(n, r[i] + 1));
                ord.push_back({max(1, b[i] - t), i});
                ord.push_back({min(m + 1, b[i] + t + 1), -i});
        }
        ord.push_back({1, 0});
        ord.push_back({m + 1, 0});
        sort(v.begin(), v.end());
        sort(ord.begin(), ord.end());
        for(int i = 0; i < v.size(); i++){
                if(i > 0 && v[i] != v[i - 1]){
                        G++;
                }
                id[v[i]] = G;
        }
        for(int i = 0; i < ord.size(); i++){
                int j = i;
                while(j < ord.size() && ord[j].fi == ord[i].fi){
                        int h = ord[j].se; j++;
                        if(h){
                                int tl = id[l[abs(h)]], tr = id[r[abs(h)]];
                                while(tl <= tr){
                                        d[tl] += (h < 0 ? -1 : 1);
                                        tl++;
                                }
                        }
                }
                if(ord[i].fi == m + 1){
                        break;
                }
                i = j - 1;
                for(int j = 1; j <= G; j++){
                        if(d[j] == 0){
                                //cout << ay << endl;
                                ay = min(m, ord[i].fi + t);
                                break;
                        }
                }
                if(ay != -1){
                        break;
                }
        }
        for(int j = 1; j <= G; j++){
                d[j] = 0;
        }
        v.clear();
        ord.clear();
        id.clear();
        G = 1;
        for(int i = 1; i <= k; i++){
                l[i] = max(1, b[i] - t);
                r[i] = min(m, b[i] + t);
                v.push_back(max(1, l[i] - 1));
                v.push_back(l[i]);
                v.push_back(r[i]);
                v.push_back(min(m, r[i] + 1));
                ord.push_back({max(1, a[i] - t), i});
                ord.push_back({min(n + 1, a[i] + t + 1), -i});
        }
        ord.push_back({1, 0});
        ord.push_back({n + 1, 0});
        sort(v.begin(), v.end());
        sort(ord.begin(), ord.end());
        for(int i = 0; i < v.size(); i++){
                if(i > 0 && v[i] != v[i - 1]){
                        G++;
                }
                id[v[i]] = G;
        }
        for(int i = 0; i < ord.size(); i++){
                int j = i;
                while(j < ord.size() && ord[j].fi == ord[i].fi){
                        //cout << ord[j].fi << " " << ord[j].se << "\n";
                        int h = ord[j].se; j++;
                        if(h){
                                int tl = id[l[abs(h)]], tr = id[r[abs(h)]];
                                while(tl <= tr){
                                        d[tl] += (h < 0 ? -1 : 1);
                                        tl++;
                                }
                        }
                }
                if(ord[i].fi == n + 1){
                        break;
                }
                //cout << "\n";
                i = j - 1;
                for(int j = 1; j <= G; j++){
                        if(d[j] == 0){
                                ax = min(n, ord[i].fi + t);
                                break;
                        }
                }
                if(ax != -1){
                        break;
                }
        }
        for(int j = 1; j <= G; j++){
                d[j] = 0;
        }
        v.clear();
        ord.clear();
        id.clear();
        return {ax, ay};
}

void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= k; i++){
                cin >> a[i] >> b[i];
        }
        int l = 0, r = 1e9;
        while(l < r){
                int m = (l + r) / 2;
                auto p = get(m);
                if(p.fi == -1 && p.se == -1){
                        r = m;
                        continue;
                }
                k++;
                a[k] = p.fi;
                b[k] = p.se;
                p = get(m);
                if(p.fi == -1 && p.se == -1){
                        r = m;
                }
                else{
                        l = m + 1;
                }
                k--;
        }
        cout << l << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}