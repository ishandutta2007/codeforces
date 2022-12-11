#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
pair<int, int> a[1111];
map<int, vector<pair<int, int> > > xx, yy;

vector<int> g[1111];
bool used[1111];
int mt[1111];
 
bool try_kuhn (int v) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

bool bad[1111];

bool used2[1111];

void dfs(int v){
    used[v] = 1;
    for (int to : g[v]){
        if (bad[v] && mt[to] == v) continue;
        if (!used2[to]){
            used2[to] = 1;
            if (mt[to] != -1 && !used[mt[to]]) dfs(mt[to]);
        }
    }
}

int main(){
    srand(time(NULL));
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    vector<pair<int, int> > tx, ty;
    for (int i = 0; i < n; i++){
        xx[a[i].x].pb(mp(a[i].y, i));
        yy[a[i].y].pb(mp(a[i].x, i));
    }
    for (auto c : xx){
        auto t = c.y;
        sort(all(t));
        for (int i = 0; i + 1 < t.size(); i++){
            tx.pb(mp(t[i].y, t[i + 1].y));
        }
    }
    for (auto c : yy){
        auto t = c.y;
        sort(all(t));
        for (int i = 0; i + 1 < t.size(); i++){
            ty.pb(mp(t[i].y, t[i + 1].y));
        }
    }

    for (int i = 0; i < tx.size(); i++) for (int j = 0; j < ty.size(); j++){
        if (a[tx[i].x].x > a[ty[j].x].x && a[tx[i].x].x < a[ty[j].y].x){
            if (a[ty[j].x].y > a[tx[i].x].y && a[ty[j].x].y < a[tx[i].y].y){
                g[i].pb(j);
                //cout << tx[i].x + 1 << ' ' << tx[i].y + 1 << ' ' << ty[j].x + 1 << ' ' << ty[j].y + 1 << endl;
            }
        }
    }

    for (int i = 0; i < 1111; i++) mt[i] = -1;
    for (int v = 0; v < tx.size(); v++){
        for (int i = 0; i < tx.size(); i++) used[i] = 0;
        try_kuhn(v);
    }

    for (int i = 0; i < ty.size(); i++) if (mt[i] != -1) bad[mt[i]] = 1;
    for (int i = 0; i < tx.size(); i++) used[i] = 0;

    for (int i = 0; i < tx.size(); i++){
        if (!bad[i]){
            dfs(i);
        }
    }
    map<pair<int, int>, int> wasy, wasx;

    for (int i = 0; i < tx.size(); i++) if (used[i]) wasx[tx[i]] = 1;
    for (int i = 0; i < ty.size(); i++) if (!used2[i]) wasy[ty[i]] = 1;

    vector<pair<pair<int, int>, pair<int, int> > > kek;
    for (auto c : yy){
        auto t = c.y;
        sort(all(t));
        int last = t[0].x;
        for (int i = 1; i < t.size(); i++){
            if (wasy[mp(t[i - 1].y, t[i].y)]){

            } else {
                kek.pb(mp(mp(last, c.x), mp(t[i - 1].x, c.x)));
                last = t[i].x;
            }
        }
        kek.pb(mp(mp(last, c.x), mp(t.back().x, c.x)));
    }
    cout << kek.size() << endl;
    for (auto c : kek) cout << c.x.x << ' ' << c.x.y << ' ' << c.y.x << ' ' << c.y.y << "\n";


    kek.clear();
    for (auto c : xx){
        auto t = c.y;
        sort(all(t));
        int last = t[0].x;
        for (int i = 1; i < t.size(); i++){
            if (wasx[mp(t[i - 1].y, t[i].y)]){

            } else {
                kek.pb(mp(mp(last, c.x), mp(t[i - 1].x, c.x)));
                last = t[i].x;
            }
        }
        kek.pb(mp(mp(last, c.x), mp(t.back().x, c.x)));
    }
    cout << kek.size() << endl;
    for (auto c : kek) cout << c.x.y << ' ' << c.x.x << ' ' << c.y.y << ' ' << c.y.x << "\n";
}