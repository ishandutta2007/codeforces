#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 500005;
int main() {    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int flag = 1;
        if (m < n) flag = 0;
        else if ((n % 2) == 0 && (m % 2)) flag = 0;
        else {
            printf("Yes\n");
            if (n % 2 == 0) {
                int e = (m - (n - 2)) / 2;
                for (int i = 1; i <= n - 2; i++)
                    printf("1 ");
                printf("%d %d\n", e, e);
            }
            else {
                for (int i = 1; i <= n - 1; i++)
                    printf("1 ");
                printf("%d\n", m - (n - 1));
            }
        }
        if (!flag) printf("No\n");
    }
    return 0;
}