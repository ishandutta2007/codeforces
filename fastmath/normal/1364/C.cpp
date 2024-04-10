#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;

    const int INF = 1000 * 1000;

    vector <int> a(n), ans(n);
    queue <int> q;
    int prv = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (a[i] == prv) {
            q.push(i);
        }   
        else {
            ans[i] = prv;

            int val = prv + 1;
            for (int j = 0; j < a[i] - prv - 1; ++j) {
                if (q.empty()) {
                    cout << "LMAO" << endl;
                    exit(1);
                }   
                int pos = q.front(); q.pop();
                ans[pos] = val;
                ++val;
            }   
        }   

        prv = a[i];

    }
    while (q.size()) {
        int i = q.front(); q.pop();
        ans[i] = INF;
    }   

    for (auto e : ans)
        cout << e << ' ';
    cout << endl;
}