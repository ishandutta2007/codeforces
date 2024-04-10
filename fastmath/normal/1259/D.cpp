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
const int N = 2e5 + 7;
string a[N];
int cnt[2];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; ++i) 
            if (a[i][0] == a[i].back()) 
                ++cnt[a[i][0] - '0'];
        if (cnt[0] == n || cnt[1] == n) {
            cout << "0\n";
            continue;
        }   
        if (cnt[0] + cnt[1] == n) {
            cout << "-1\n";
            continue;
        }   
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i][0] == a[i].back())
                continue;
            else
                ++cnt[a[i][0] - '0'];
        }   

        cout << abs(cnt[0] - cnt[1]) / 2 << '\n';
        set <string> ms;
        for (int i = 0; i < n; ++i)
            ms.insert(a[i]);
        int w = abs(cnt[0] - cnt[1]) / 2;
        int t;
        if (cnt[0] > cnt[1]) t = 0;
        else t = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i][0] == a[i].back())
                continue;
            
            if (a[i][0] == '0' + t && w) {
                string r = a[i];
                reverse(all(r));
                if (ms.find(r) == ms.end()) {
                    cout << i + 1 << ' ';
                    --w;
                }   
            }   
        }
        cout << '\n';
    }   
}