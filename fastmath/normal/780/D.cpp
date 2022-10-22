#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1001;
string a[N], b[N], ans[N];
string n1[N], n2[N];
map <string, vector <int> > d;
bool used[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        d[a[i].substr(0, 3)].app(i);
        n1[i] = a[i].substr(0, 3);
        n2[i] = a[i].substr(0, 2) + b[i][0];
    }   
    set <string> ban;
    for (auto e : d) 
        if (e.s.size() > 1) 
            for (int i : e.s) {
                ans[i] = n2[i];
                ban.insert(n2[i]);
                used[i] = 1;
            }

    bool did = 0;
    do {
    did = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            if (ban.find(n1[i]) != ban.end()) {
                ans[i] = n2[i];
                used[i] = 1;
                did = 1;
                ban.insert(n2[i]);
            }
            else if (ban.find(n2[i]) != ban.end()) {
                ans[i] = n1[i];
                used[i] = 1;
                did = 1;
                ban.insert(n1[i]);
            }   
        } 
    }   
    } while (did); 
    
    for (int i = 0; i < n; ++i) 
        if (!used[i]) 
            ans[i] = n1[i];

    set <string> ms;
    for (int i = 0; i < n; ++i) {
        if (ms.find(ans[i]) != ms.end()) {
            cout << "NO\n";
            exit(0);
        }   
        ms.insert(ans[i]);
    }   
    cout << "YES\n";
    for (int i = 0; i < n; ++i) 
        cout << ans[i] << '\n';
}