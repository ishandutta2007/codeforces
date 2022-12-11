#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, m;
int a[1505][1505];
int b[1505][1505];

int bal[1505];
vector<int> KEK[1505];

map<vector<int>, vector<int>> SUKA;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> b[i][j];


    for (int i = 0; i < n; ++i) {
        vector<int> now; now.resize(m);
        for (int j = 0; j < m; ++j) now[j] = a[i][j];
        SUKA[std::move(now)].pb(i);
    }


    for (auto& [w1, w2] : SUKA) reverse(all(w2));

    vector<vector<int>> t;
    vector<int> start;

    for (int i = 0; i < n; ++i) {
        vector<int> now(m);
        for (int j = 0; j < m; ++j) now[j] = b[i][j];
        if (SUKA[now].size() == 0) {
            cout << -1; exit(0);
        }
        start.pb(SUKA[now].back());
        SUKA[now].pop_back();
    }

    t.pb(start);

    vector<int> st;

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i + 1 < n; ++i) {
            if (a[start[i]][j] > a[start[i + 1]][j]) {
                bal[j]++;
                KEK[i].pb(j);
             //   cout << "AAAAAAAAA " <<  i << ' ' << j << ' ' << start[i] << ' ' << start[i + 1] << endl;
            }
        }
       // cout << j << ' ' << bal[j] << endl;
        if (bal[j] == 0) st.pb(j);
    }

    vector<int> ans;
    while (st.size()) {
        int v = st.back(); st.pop_back();
        ans.pb(v);
        vector<vector<int>> nt;

        int sum = 0;
        for (auto& c : t) {
            vector<int> now;
            now.pb(c[0]);

            for (int i = 0; i + 1 < c.size(); ++i) {
                if (a[c[i]][v] != a[c[i + 1]][v]) {

                    int pos = sum + i;
                    for (auto W : KEK[pos]) {
                        bal[W]--;
                        //cout << "WTF " << pos << endl;
                        if (bal[W] == 0) st.pb(W);
                    }

                    nt.emplace_back(now);
                    now.clear();
                }
                now.pb(c[i + 1]);
            }
            sum += c.size();
            nt.emplace_back(std::move(now));
        }

        swap(t, nt);
    }

    for (auto& c : t){ 
        for (int i = 0; i + 1 < c.size(); ++i) {
            if (c[i] > c[i + 1]) cout << -1, exit(0);
        }
    }
    cout << ans.size() << endl;
    reverse(all(ans));
    for (int x : ans) cout << x + 1 << ' ';
}