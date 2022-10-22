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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, m;
    cin >> n >> m;

    string add;
    getline(cin, add);

    vector <int> mon = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    vector <string> mem;
    vector <int> a;
    while (getline(cin, add)) {
        int t = 0;
        int mo = stoll(add.substr(5, 2));

        for (int i = 0; i < mo - 1; ++i) {
            t += 24 * 60 * 60 * mon[i];                        
        }   
        int day = stoll(add.substr(8, 2));
        t += 24 * 60 * 60 * (day - 1);

        int h = stoll(add.substr(11, 2));
        t += h * 60 * 60;

        int mn = stoll(add.substr(14, 2));
        t += mn * 60;

        int sec = stoll(add.substr(17, 2));
        t += sec;

        a.app(t);
        mem.app(add);
    }   
    
    for (int i = 0; i < a.size(); ++i) {
        int l = lower_bound(all(a), a[i] - n + 1) - a.begin();
        if (i - l + 1 >= m) {
            cout << mem[i].substr(0, 19) << endl;
            exit(0);
        }   
    }   
    cout << -1 << endl;
}