#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const int INF = (int)1E9;
const int MAXN = (int)11000;

using namespace std;


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s, sb, se;
    int len[3], mlen;
        cin >> s;
        cin >> sb;
        cin >> se;
        len[0] = s.size();
        len[1] = sb.size();
        len[2] = se.size();
        mlen = max(len[0], max(len[1], len[2]));

    const int ppow = (int)31;

        vector<int64> p(mlen), h1(mlen), h2(mlen), h3(mlen);
        p[0] = 1;
        for (int i = 1; i < mlen; i++)
                p[i] = (p[i - 1] * ppow);

    h1[0] = s[0] - 'a' + 1;
    for (int i = 1; i < len[0]; i++)
                h1[i] = h1[i - 1] * ppow + (s[i] - 'a' + 1);
    h2[0] = sb[0] - 'a' + 1;
    for (int i = 1; i < len[1]; i++)
                h2[i] = h2[i - 1] * ppow + (sb[i] - 'a' + 1);
    h3[0] = se[0] - 'a' + 1;
    for (int i = 1; i < len[2]; i++)
                h3[i] = h3[i - 1] * ppow + (se[i] - 'a' + 1);

    vector<int64> hash;
    forn(i, len[0])
        for (int j = i; j < len[0]; j++)
            if ((i + len[1]) <= len[0] && (j + len[2]) <= len[0] && (i + len[1] <= j + len[2]))
                if (h1[i + len[1] - 1] - (i > 0 ? h1[i - 1] : 0) * p[len[1]] == h2[len[1] - 1])
                    if (h1[j + len[2] - 1] - (j > 0 ? h1[j - 1] : 0) * p[len[2]] == h3[len[2] - 1]) {
                        int64 cur = h1[j + len[2] - 1] - (i > 0 ? h1[i - 1] : 0) * p[j + len[2] - i];
                        hash.push_back(cur);
                    }

    int ans = (hash.size() != 0);
    sort(all(hash));
    for (int i = 1; i < hash.size(); i++)
        ans += (hash[i - 1] != hash[i]);
    cout << ans << endl;

    return 0;
}