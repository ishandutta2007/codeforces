#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 200200;
const int mod = 998244353;

int n;
int f[N];
long long a[N];
long long s[N], t[N], A[N], B[N];

void upd(int x, int g)
{
        x += 1;

        while(x < N){
                f[x] += g;
                x += x & -x;
        }
}

int get(int x)
{
        x += 1;

        int res = 0;
        while(x > 0){
                res += f[x];
                x -= x & -x;
        }
        return res;
}

long long solve(const vector < long long > &A, const vector < long long > &B)
{
        long long res = 0;
        vector < long long > shit;
        for(auto x: A){
                shit.push_back(x);
        }
        sort(shit.begin(), shit.end());
        for(int i = 0; i <= n + 1; i++){
                f[i] = 0;
        }
        for(int i = 0; i < A.size(); i++){
                upd(lower_bound(shit.begin(), shit.end(), A[i]) - shit.begin(), 1);
                res += get(lower_bound(shit.begin(), shit.end(), B[i]) - shit.begin() - 1);
        }

        return res;
}

long long solve(int l, int r, long long to_add)
{
        s[l - 1] = t[r - 1] = 0;
        for(int i = l; i <= r; i++){
                s[i] = s[i - 1] + a[i];
                t[i] = a[i] - t[i - 1];

                A[i] = s[i] - t[i];
                B[i] = s[i] + t[i];
        }
        to_add -= s[r];

        vector < long long > aa[2], bb[2];
        for(int i = l; i < r; i++){
                aa[i % 2].push_back(to_add + A[i]);
                bb[i % 2].push_back(- B[i]);
        }

        long long res = 0;
        for(int i = 0; i < 2; i++){
                res += solve(aa[i], bb[i]);
        }
        return res;
}

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];

                s[i] = s[i - 1] + a[i];
                t[i] = a[i] - t[i - 1];
        }
        a[n + 1] = a[0] = 0;

        long long res = 0;

        for(int i = 0; i <= n; i++){
                res += (s[n] - s[i] < s[i]);
        }

        for(int x = 0; x < 2; x++){
                for(int y = 0; y < 2; y++){
                        res += solve(1 + x, n - y, a[n + 1 - y] - a[x]);
                }
        }

        cout << res % mod << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}