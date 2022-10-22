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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n), cnt(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            ++cnt[a[i]];
        }   

        auto check = [&] (int m) {

            vector <int> cnt1 = cnt;            

            set <ii> can;
            for (int i = 0; i < n; ++i)
                can.insert(mp(cnt1[i], i));
            vector < vector <int> > add(n);
            for (int i = 0; i < n; ++i) {
                for (int c : add[i])
                    can.insert(mp(cnt1[c], c));

                if (can.empty())
                    return 0;
                auto t = *can.rbegin();
                can.erase(t);
                if (t.f == 0)
                    return 0;

                int c = t.s;
                --cnt1[c];
                if (i + m + 1 < n)
                    add[i + m + 1].app(c);
            }   
            return 1;            
        };      

        int l = 0;
        int r = n-1;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (check(m))
                l = m;
            else
                r = m;
        }   
        cout << l << endl;
    }   

}