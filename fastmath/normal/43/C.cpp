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
    vector <int> cnt(3);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int sum = 0;
        for (char c : s) {
            sum += c - '0';
        }
        cnt[sum%3]++;

    }   

    cout << min(cnt[1], cnt[2]) + cnt[0]/2 << endl;
}