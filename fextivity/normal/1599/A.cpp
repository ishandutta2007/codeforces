#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e6 + 10;
int n, a[N];
char S[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    cin >> (S + 1);
    int l = 1, r = n;
    vi ans;
    for (int i = n; i > 1; --i)
        if (S[i] != S[i - 1])
        {
            if (S[i] == 'L') ans.eb(-r);
            else ans.eb(r);
            r--;
        }
        else
        {
            if (i & 1)
            {
                if (S[i] == 'L') ans.eb(-l);
                else ans.eb(l);
            }
            else
            {
                if (S[i] == 'L') ans.eb(l);
                else ans.eb(-l);
            }
            l++;
        }
    if (S[1] == 'L') ans.eb(-l);
    else ans.eb(l);
    reverse(all(ans));
    for (int i = 0; i < n; ++i)
        if (ans[i] < 0) cout << a[-ans[i]] << " L\n";
        else cout << a[ans[i]] << " R\n";
    return 0;
}