#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

pii dp[105][105][105];
char u[105][105][105], z[9];
string s1,s2,virus,anss;

pii f(int s1i, int s2i, int vi) { /// 1 - s1i--, 2 - s2i--, 3 - s1[i] == s2[j] == virus[k], 4 - s1[i] == s2[j] != virus[k]
    if (s1i < 0 || s2i < 0 || vi < 0) return make_pair(0,0);
    if (!u[s1i][s2i][vi]) {
        u[s1i][s2i][vi] = 1;
        int ans1 = -1, ans2 = 0;
        pii qqq;
        qqq = f(s1i-1, s2i, vi); if (qqq.first > ans1) ans1 = qqq.first, ans2 = 1;
        qqq = f(s1i, s2i-1, vi); if (qqq.first > ans1) ans1 = qqq.first, ans2 = 2;
        if (s1[s1i] == s2[s2i]) {
            if (virus[vi] == s1[s1i]) {
                if (vi != 0) {
                    qqq = f(s1i-1, s2i-1, vi-1); ++qqq.first; if (qqq.first > ans1) ans1 = qqq.first, ans2 = 3;
                }
            } else {
                *z = s1[s1i];
                string t1 = "", t2 = virus;
                t1 += z;
                t1 += virus.substr(vi+1, virus.size() - vi - 1);
                int mx = 0;
                for (int i = 1; i <= t1.size() && i <= t2.size(); ++i) {
                    if (t1.substr(0, i) == t2.substr(t2.size() - i, i)) mx = i;
                }

                if (virus.size() - 1 - mx >= 0) {
                    qqq = f(s1i-1, s2i-1, virus.size() - 1 - mx); ++qqq.first; if (qqq.first > ans1) ans1 = qqq.first, ans2 = 1000 + mx;
                }
            }
        }
        dp[s1i][s2i][vi] = make_pair(ans1, ans2);
        /// cerr << "s1i = " << s1i << ", s2i = " << s2i << ", vi = " << vi << ",   ans1 = " << ans1 << ", ans2 = " << ans2 << endl;
    }
    return dp[s1i][s2i][vi];
}

int main()
{
    cin >> s1 >> s2 >> virus;
    int a = s1.size() - 1, b = s2.size() - 1, mvi = virus.size() - 1;
    pii ans = f(a,b,mvi);
    while (ans.first > 0) {
        if (ans.second == 1) --a;
        else if (ans.second == 2) --b;
        else if (ans.second == 3) {
            *z = s1[a];
            anss += z;
            --a; --b;
            --mvi;
        } else {
            *z = s1[a];
            anss += z;
            --a; --b;
            mvi = virus.size() - 1 - (ans.second - 1000);
        }
        ans = f(a,b,mvi);
    }
    if (anss == "") anss = "0";
    reverse(anss.begin(), anss.end());
    cout << anss;

    return 0;
}