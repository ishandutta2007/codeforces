#include <bits/stdc++.h>
#define pii pair<ld,ld>
using namespace std;
typedef long long ll;
typedef long double ld;

char u[105][105][105];
pair<ld,ld> dp[105][105][105];

pii f(int r, int s, int p) {
    if (r == 0 && s == 0) return make_pair(0,0);
    if (r == 0 && p == 0) return make_pair(0,1);
    if (s == 0 && p == 0) return make_pair(1,0);

    if (r == 0) return make_pair(0,1);
    if (s == 0) return make_pair(0,0);
    if (p == 0) return make_pair(1,0);

    if (!u[r][s][p]) {
        u[r][s][p] = 1;
        pii qqq1 = f(r-1,s,p);
        pii qqq2 = f(r,s-1,p);
        pii qqq3 = f(r,s,p-1);

        dp[r][s][p] = make_pair(qqq1.first * ld(p*r) / ld(r*s + s*p + p*r) +
                                qqq2.first * ld(r*s) / ld(r*s + s*p + p*r) +
                                qqq3.first * ld(s*p) / ld(r*s + s*p + p*r),

                                qqq1.second * ld(p*r) / ld(r*s + s*p + p*r) +
                                qqq2.second * ld(r*s) / ld(r*s + s*p + p*r) +
                                qqq3.second * ld(s*p) / ld(r*s + s*p + p*r));
    }
    return dp[r][s][p];
}

int main()
{
    int r,s,p;
    cin >> r >> s >> p;
    pii qqq = f(r,s,p);

    cout.precision(17);
    cout << fixed << qqq.first << " ";
    cout.precision(17);
    cout << fixed << qqq.second << " ";
    cout.precision(17);
    cout << fixed << ((ld)1 - qqq.first - qqq.second);

    return 0;
}