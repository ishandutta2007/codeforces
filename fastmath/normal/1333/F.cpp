#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 5e5 + 7;
bool used[N], added[N];
vector <int> md[N];
int cost[N], cnt_cost[N];
int pd[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            md[j].app(i);   
    int n;
    cin >> n;
    cnt_cost[0] = n;
    int ans = 0;
    for (int sz = 1; sz <= n; ++sz) {
        while (!cnt_cost[ans])
            ++ans;

        int x;
        if (ans == 0) 
            x = 1;
        else {
            pd[ans] = max(pd[ans], ans);
            while (used[pd[ans]] || cost[pd[ans]] != ans)
                pd[ans] += ans;
            x = pd[ans];
        }   

        used[x] = 1;
        --cnt_cost[cost[x]];
        
        if (sz > 1)
            cout << ans << ' ';

        for (int d : md[x]) {
            if (!added[d]) {
                added[d] = 1;
                for (int i = d; i <= n; i += d) {
                    if (!used[i] && cost[i] < d) {
                        --cnt_cost[cost[i]];
                        cost[i] = d;
                        ++cnt_cost[cost[i]];
                    }   
                }   
            }   
        }   
    }   
    cout << endl;

    #ifdef HOME
    cout << Time << endl;
    #endif
}