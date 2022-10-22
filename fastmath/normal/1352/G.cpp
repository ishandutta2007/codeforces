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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 1) {
            cout << "1" << endl;
            continue;
        }   
        else if (n <= 3) {
            cout << -1 << endl;
            continue;
        }   
        else if (n == 4) {
            cout << "3 1 4 2" << endl;
            continue;
        }   

        vector <int> ans;
        for (int i = 1; i <= n; i += 2)
            ans.app(i);
        int cur = n;
        if (cur % 2 == 0)
            --cur;
        cur -= 3;
        ans.app(cur);

        if (cur + 4 <= n) {
            cur += 4;
        }   
        else {
            cur += 2;
        }   
        ans.app(cur);

        vector <bool> used(n + 1);
        for (int e : ans)
            used[e] = 1;

        while (1) {
            if (cur > 2 && !used[cur - 2]) {
                cur -= 2;
            }   
            else if (cur > 4 && !used[cur - 4]) {
                cur -= 4;
            }   
            else 
                break;
            ans.app(cur);
            used[cur] = 1;
        }

        for (int e : ans)
            cout << e << ' ';
        cout << endl;

    }   

}