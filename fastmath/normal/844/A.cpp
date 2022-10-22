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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s;
    int k;
    cin >> s;
    cin >> k;

    set <char> ms;
    for (char c : s)
        ms.insert(c);
    
    if (k > s.size()) {
        cout << "impossible\n";
    }   
    else
        cout << max(0ll,k - ms.size()) << '\n';
}