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
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (a[i] == '4')
                x++;
            else
                y++;
        }   
    }   
    cout << max(x, y) << endl;
}