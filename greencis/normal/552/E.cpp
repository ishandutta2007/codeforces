#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

string s;
int n;
ll pref[5005],suff[5005];
ll pref_last_multiply[5005], suff_last_multiply[5005];
ll ans;

int main()
{
    cin >> s;
    n = s.size();

    if (n == 1) { cout << s; return 0; }

    pref_last_multiply[0] = pref[0] = s[0] - 48;
    for (int i = 2; i < n; i += 2) {
        if (s[i-1] == '+') {
            pref[i] = pref[i-2] + ll(s[i] - 48);
            pref_last_multiply[i] = ll(s[i] - 48);
        } else {
            pref[i] = pref[i-2] - pref_last_multiply[i-2] + pref_last_multiply[i-2] * ll(s[i]-48);
            pref_last_multiply[i] = pref_last_multiply[i-2] * ll(s[i]-48);
        }
    }

    suff_last_multiply[n-1] = suff[n-1] = s[n-1] - 48;
    for (int i = n-3; i >= 0; i -= 2) {
        if (s[i+1] == '+') {
            suff[i] = suff[i+2] + ll(s[i] - 48);
            suff_last_multiply[i] = ll(s[i] - 48);
        } else {
            suff[i] = suff[i+2] - suff_last_multiply[i+2] + suff_last_multiply[i+2] * ll(s[i]-48);
            suff_last_multiply[i] = suff_last_multiply[i+2] * ll(s[i]-48);
        }
    }

    for (int i = 0; i < n; ++i)
        ans = max(ans, pref[i]);

    for (int i = 0; i < n-2; i += 2) {
        ll calc_cur = s[i] - 48;
        ll calc_last_multiply = s[i] - 48;

        for (int j = i + 2; j < n; j += 2) {
            ll cur = 0;
            ll cc = 0;
            if (s[j-1] == '+') {
                calc_cur += s[j] - 48;
                calc_last_multiply = s[j] - 48;
            } else {
                calc_cur = calc_cur - calc_last_multiply + calc_last_multiply * ll(s[j] - 48);
                calc_last_multiply *= ll(s[j] - 48);
            }

            cc = calc_cur;

            if (i != 0) {
                if (s[i-1] == '+') {
                    cur += pref[i-2];
                } else {
                    cur += pref[i-2] - pref_last_multiply[i-2];
                    cc *= pref_last_multiply[i-2];
                }
            }
            if (j != n-1) {
                if (s[j+1] == '+') {
                    cur += suff[j+2];
                } else {
                    cur += suff[j+2] - suff_last_multiply[j+2];
                    cc *= suff_last_multiply[j+2];
                }
            }
            cur += cc;
            ans = max(ans, cur);
        }
    }

    cout << ans;

    return 0;
}