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
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
bool used[N], del[N];
char t[N];
int num[N];
bool can[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> num[i];
        if (!used[num[i]]) {
            used[num[i]] = 1;
            del[num[i]] = t[i] == '-';
        }   
    }
    for (int i = 1; i <= n; ++i)
        can[i] = 1;
    int cnt = 0;
    set <int> no;
    for (int i = 1; i <= n; ++i) {
        if (del[i])
            ++cnt;
        else if (used[i])
            no.insert(i);
    }   
    if (cnt) {
        for (int e : no)
            can[e] = 0;
        no.clear();
    }       
    for (int i = 0; i < q; ++i) {
        if (t[i] == '+') {
            no.erase(num[i]);
            ++cnt;
        }   
        else {
            --cnt;
            if (can[num[i]])
                no.insert(num[i]);
        }   
        if (cnt) {
            for (int e : no)
                can[e] = 0;
            no.clear();
        }   
    }   
    vector <int> ans;
    for (int i = 1; i <= n; ++i)
        if (can[i])
            ans.app(i);
    cout << ans.size()  << endl;
    for (int e : ans)
        cout << e << ' ';
    cout << endl;                               
}