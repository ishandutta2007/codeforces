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


        string a, b;
        cin >> a >> b;

        int s = 0, d = 1;
        bool add = 0;

        vector <int> ans;
        for (int i = n - 1; i; --i) {
            bool have = (a[s + d * i] - '0') ^ add;
            if (have == b[i] - '0') {

            }   
            else {

                bool have_s = (a[s] - '0') ^ add;

                if (have_s != b[i] - '0') {
                    ans.app(i + 1);
                }   
                else {
                    ans.app(1);
                    ans.app(i + 1);
                }   
                s = s + d * i;
                d = -d;
                add ^= 1;
            }
        }   

        bool have = (a[s] - '0') ^ add;
        if (have != b[0] - '0') {
            ans.app(1);
        }   

        cout << ans.size() << ' ';
        for (auto e : ans)
            cout << e << ' ';
        cout << endl;
    }   

}