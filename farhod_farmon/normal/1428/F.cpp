#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n;
char a[N];
long long res;

void solve(int l, int r)
{
        if(l == r){
                res += (a[l] == '1');
                return;
        }
        int m = (l + r) / 2;
        solve(l, m);
        solve(m + 1, r);

        vector < int > A, B;
        vector < long long > suf;
        int xa = 0, xb = 0;
        while(m + 1 + xb <= r && a[m + 1 + xb] == '1') xb += 1;
        while(m - xa >= l && a[m - xa] == '1') xa += 1;

        int cnt = 0, mx = xb;
        for(int i = m + 1 + xb; i <= r; i++){
                if(a[i] == '1'){
                        cnt += 1;
                } else{
                        cnt = 0;
                }
                mx = max(mx, cnt);
                B.push_back(mx);
        }
        cnt = 0;
        mx = xa;
        for(int i = m - xa; i >= l; i--){
                if(a[i] == '1'){
                        cnt += 1;
                } else{
                        cnt = 0;
                }
                mx = max(mx, cnt);
                A.push_back(mx);
        }

        suf.resize((int)A.size() + 1);
        suf[suf.size() - 1] = 0;
        int C = xa + xb;
        for(int i = (int)A.size() - 1; i >= 0; i--){
                suf[i] = suf[i + 1] + max(C, A[i]);
        }

        res += 1ll * xb * (xb + 1) / 2 * xa;
        res += 1ll * xa * (xa + 1) / 2 * xb;
        for(int i = 0, j = 0; i < (int)B.size(); i++){
                int x = min(xa, max(0, B[i] - xb));
                res += 1ll * B[i] * x + 1ll * xb * (xa - x);
                res += 1ll * xa * (xa + 1) / 2;
                res -= 1ll * x * (x + 1) / 2;

                while(j < A.size() && B[i] >= A[j]){
                        j += 1;
                }
                res += 1ll * j * max(C, B[i]);
                res += suf[j];
        }
        for(int i = 0; i < (int)A.size(); i++){
                int x = min(xb, max(0, A[i] - xa));
                res += 1ll * A[i] * x + 1ll * xa * (xb - x);
                res += 1ll * xb * (xb + 1) / 2;
                res -= 1ll * x * (x + 1) / 2;
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        solve(1, n);

        cout << res << "\n";
}