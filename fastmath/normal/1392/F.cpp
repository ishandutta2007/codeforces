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
    int n;
    cin >> n;
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    int al = 0;
    for (int i = 1; i < n; ++i) {
        al += n - i;
    }   
    
    auto mod = [&] (int x) {
        return (x % n + n) % n;
    };  
    int nul = mod(n - al + sum);

    int add = 0;
    int S = (sum - (al - mod(n - nul))) / n;
    cout << S << ' ';
    for (int i = 1; i < n; ++i) {
        if (i != nul) {
            add++;
        }   
        cout << S + add << ' ';
    }   
    cout << endl;
}