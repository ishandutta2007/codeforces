#include <bits/stdc++.h>
using namespace std;

int cnt1[256], cnt2[256];

int main()
{
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    for (int i = 0; s[i]; ++i)
        ++cnt1[s[i]];
    for (int i = 0; t[i]; ++i)
        ++cnt2[t[i]];
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < 256; ++i) {
        int mn = min(cnt1[i], cnt2[i]);
        ans1 += mn;
        cnt1[i] -= mn;
        cnt2[i] -= mn;
    }
    for (int i = 'A'; i <= 'Z'; ++i) {
        int mn = min(cnt1[i], cnt2[i ^ 32]);
        ans2 += mn;
        cnt1[i] -= mn;
        cnt2[i ^ 32] -= mn;
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        int mn = min(cnt1[i], cnt2[i ^ 32]);
        ans2 += mn;
        cnt1[i] -= mn;
        cnt2[i ^ 32] -= mn;
    }
    cout << ans1 << ' ' << ans2 << endl;

    return 0;
}