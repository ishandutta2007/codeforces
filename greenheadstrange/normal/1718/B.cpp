//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
#define maxn 200005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int S = 65;
ll cur[S];
int hv[S];
int a[105];

int main() {
    int t;
    cin >> t;
    cur[0] = cur[1] = 1;
    for (int i = 2; i < S; i++)
        cur[i] = cur[i - 1] + cur[i - 2];
    while (t--) {
        int k;
        cin >> k;
        memset(hv, 0, sizeof(hv));
        auto ins = [&](int y, int tp) {
            int x = y;
            for (int j = S - 1; j >= 1; j--) {
                if (x >= cur[j]) {
                    hv[j] += tp;
                    x -= cur[j];
                    if (j == 1) return 0;
                }
            }
            return 1;
        };
        for (int i = 1; i <= k; i++) {
            scanf("%d", &a[i]);
            ins(a[i], 1);
        }
        int ff = 0;
        for (int i = 1; i <= k; i++) {
            int flag = 1;
            if (!a[i]) continue;
            ins(a[i], -1);
            flag &= ins(a[i] - 1, 1);
            for (int j = 1; j < S - 1; j++) {
                if (hv[j] >= 2) flag = 0;
                if (hv[j + 1] && !hv[j]) flag = 0;
            }
            ins(a[i], 1);
            ins(a[i] - 1, -1);
            ff |= flag;
        }
        if (ff) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return (0-0); //<3
}