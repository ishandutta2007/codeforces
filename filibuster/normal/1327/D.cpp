#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < n; i++)

using namespace std;
using li = long long;
using pii = pair<int, int>;
using pli = pair<li, li>;
using vi = vector<int>;
using vli = vector<li>;
using vpli = vector<pli>;

istream& operator >>(istream& cin, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cin >> a[i];
    return cin;
}

ostream& operator <<(ostream& cout, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    return cout;
}

const int M = 998244353;
const int INF = 1e9;
const int N = 2e5 + 13;


//int cyc[N], ind[N];
//vector<int> cl;
//
//void dfs(int v, int c) {
//    cyc[v] = c;
//    ind[v] = cl.size();
//    cl.push_back(v);
//
//    dfs();
//}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), c(n);
    cin >> a >> c;

    for(int i = 0; i < n; i++) {
        a[i]--;
        if(a[i] == i) {
            cout << 1 << endl;
            return;
        }
    }


    vector<int> cyc(n, -1);//, ind(n, -1);
    vector<vector<int>> cl;

    for(int i = 0; i < n; i++)
        if(cyc[i] == -1) {
            int v = i;
            cl.push_back(vector<int> (0));
            while(cyc[v] == -1) {
                cyc[v] = cl.size() - 1;
//                ind[v] = cl.back().size();
                cl.back().push_back(c[v]);
                v = a[v];
            }
        }

//    for(int i = 0; i < cl.size(); i++) {
//        for(auto x : cl[i])
//            cout << x + 1 << ' ';
//        cout << endl;
//    }

    int ans = n;

    for(int i = 0; i < cl.size(); i++) {
//        for(auto x : cl[i])
//            cout << x << ' ';
//        cout << endl;
        for(int j = 1; j * 1ll * j <= cl[i].size(); j++) {
            if(cl[i].size() % j == 0) {
                int d = j;
//                cout << d << endl;
                vector<bool> fl(d, false);
                for(int l = d; l < cl[i].size(); l++)
                    if(cl[i][l] != cl[i][l - d]) {
                        fl[l % d] = true;
                    }

                for(int l = 0; l < d; l++)
                    if(!fl[l]) {
                        ans = min(ans, d);
                        break;
                    }


                d = cl[i].size() / j;
                fl.erase(fl.begin(), fl.end());
                fl.resize(d, false);
                for(int l = d; l < cl[i].size(); l++)
                    if(cl[i][l] != cl[i][l - d]) {
                        fl[l % d] = true;
                    }

                for(int l = 0; l < d; l++)
                    if(!fl[l]) {
                        ans = min(ans, d);
                        break;
                    }
            }
        }
    }

    cout << ans << endl;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}