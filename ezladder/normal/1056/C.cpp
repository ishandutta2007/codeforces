#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m;
int a[100007];
bool was[100007];
int to[100007];
int fa[100007];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < 2 * n; i++) cin >> a[i], to[i] = -1;
    vector<pair<int, int> > g;
    for (int i = 0; i < m; i++){
        int w1, w2;
        cin >> w1 >> w2;
        w1--; w2--;
        g.pb(mp(w1, w2));
        was[w1] = was[w2] = 1;
        to[w1] = w2;
        to[w2] = w1;
    }
    int t;
    cin >> t;
    set<pair<int, int> > se;
    for (int i = 0; i < 2 * n; i++) if (!was[i]) se.insert(mp(a[i], i));
    if (t == 1){
        for (int i = 0; i < g.size(); i++){
            if (a[g[i].x] > a[g[i].y]) cout << g[i].x + 1 << endl;
            else cout << g[i].y + 1 << endl;
            int ans;
            cin >> ans;
        }
        while(se.size()){
            auto now = *(--se.end());
            se.erase(now);
            cout << now.y + 1 << endl;
            int ans;
            cin >> ans;
            se.erase(mp(a[ans - 1], ans - 1));
        }
    } else {
        bool f = 0;
        for (int it = 0; it < n; it++){
            int ans;
            cin >> ans;
            ans--;
            fa[ans] = 1;
            if (to[ans] == -1){
                se.erase(mp(a[ans], ans));
                f = 1;
                break;
            } else {
                fa[to[ans]] = 1;
                cout << to[ans] + 1 << endl;
            }
        }
        if (f){
            for (int i = 0; i < g.size(); i++) if (!fa[g[i].x]){
                if (a[g[i].x] > a[g[i].y]) cout << g[i].x + 1 << endl;
                else cout << g[i].y + 1 << endl;
                int ans;
                cin >> ans;
            }
            while(se.size()){
                auto now = *(--se.end());
                se.erase(now);
                cout << now.y + 1 << endl;
                if (se.size()){
                    int ans;
                    cin >> ans;
                    se.erase(mp(a[ans - 1], ans - 1));
                }
            }
        }
    }
}