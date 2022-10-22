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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    string s1 = s;
    string t1 = t;
    sort(all(s1));
    sort(all(t1));
    if (s1 != t1) {
        cout << -1 << endl;
        exit(0);
    }   

    vector <int> cnt(2); // 0/1 in the end
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i])
            continue;

        int t = s[i] - '0';
        if (cnt[t^1]) {
            --cnt[t^1];
            ++cnt[t];
        }   
        else {
            ++ans;
            ++cnt[t];
        }   
    }   
    cout << ans << endl;
}