#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

#define pb push_back
struct Aho{
    struct Vert{
        int to[26], au[26];
        int suf, p, c, len, suf1;
        Vert() { for (int i = 0; i < 26; i++) to[i] = -1, au[i] = 0; suf = 0; }
    };

    Vert t[500007];
    int sz;

    Aho() { sz = 1; }

    int add(string &s){
        int v = 0;
        for (char c : s){
            int now = c - 'a';
            if (t[v].to[now] == -1) {
                t[sz].p = v, t[sz].c = now, t[sz].len = t[v].len + 1, t[v].to[now] = sz++;
            }
            v = t[v].to[now];
        }
        return v;
    }

    void buildSuf(){
        vector<int> st;
        int uk = 0;
        st.push_back(0);
        while(uk < st.size()){
            int v = st[uk++];
            if (v == 0 || t[v].p == 0) t[v].suf = 0;
            else {
                int cur = t[t[v].p].suf;
                while(1){
                    if (t[cur].to[t[v].c] != -1){
                        t[v].suf = t[cur].to[t[v].c];
                        break;
                    }
                    if (cur == 0) break;
                    cur = t[cur].suf;
                }
            }
            for (int i = 0; i < 26; i++) if (t[v].to[i] != -1) st.pb(t[v].to[i]);
        }
    }

    void buildAu(){
        vector<int> st;
        int uk = 0;
        st.push_back(0);
        while(uk < st.size()){
            int v = st[uk++];
            for (int i = 0; i < 26; i++){
                if (t[v].to[i] != -1) t[v].au[i] = t[v].to[i];
                else {
                    t[v].au[i] = t[t[v].suf].au[i];
                }
            }
            for (int i = 0; i < 26; i++) if (t[v].to[i] != -1) st.pb(t[v].to[i]);
        }
    }
} aho;

const int N = 3e5+7;
bool used[N];
int vt[N];
multiset <int> ms[N];
int x[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, m;
    cin >> n >> m;
    vector <string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        x[i] = 0;
        vt[i] = aho.add(a[i]);

        //debug(vt[i]);

        ms[vt[i]].insert(0);
        used[a[i].size()] = 1;
    }   

    aho.buildSuf();
    aho.buildAu();

    vector <int> ord;
    for (int i = 0; i < aho.sz; ++i)
        ord.app(i);

    auto comp = [&] (int u, int v) {
        return aho.t[u].len < aho.t[v].len;
    };  

    sort(all(ord), comp);
    for (int u : ord) {
        if (u) {
            int to = aho.t[u].suf;
            if (to == 0) {
                aho.t[u].suf1 = 0;
            }   
            else if (ms[to].size()) {
                aho.t[u].suf1 = to;
            }   
            else {
                aho.t[u].suf1 = aho.t[to].suf1;
            }   
        }   
    }   

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            cin >> i;
            i--;
            assert(ms[vt[i]].count(x[i]));
            ms[vt[i]].erase(ms[vt[i]].find(x[i]));
            cin >> x[i];
            ms[vt[i]].insert(x[i]);
        }   
        else {
            int ans = -1;
            
            string s;
            cin >> s;

            int u = 0;
            for (char c : s) {
                u = aho.t[u].au[c - 'a'];
                int up = u;
                int h = 0;
                while (up) {
                    assert(up > 0);
                    if (ms[up].size()) {
                        ans = max(ans, *ms[up].rbegin());
                    }
                    up = aho.t[up].suf1;
                    h++;
                    assert(h <= 800);
                }   
            }   

            cout << ans << endl;
        }   
    }   
}