#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

struct node
{
        int sum;
        int mn, mx;
        node()
        {
                sum = mn = mx = 0;
        }
        node(int x1, int x2, int y2)
        {
                sum = x1;
                mn = x2;
                mx = y2;
        }
};

node comb(node l, node r)
{
        node res;
        res.sum = l.sum + r.sum;
        res.mn = min(l.mn, r.mn + l.sum);
        res.mx = max(l.mx, r.mx + l.sum);
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, m;
                cin >> n >> m;
                string s;
                cin >> s;
                vector < node > A(n + 2, {0, 0, 0}), B(n + 2, {0, 0, 0});
                for(int i = 1; i <= n; i++){
                        int g = (s[i - 1] == '+' ? 1 : -1);
                        A[i] = comb(A[i - 1], {g, g, g});
                }
                for(int i = n; i >= 1; i--){
                        int g = (s[i - 1] == '+' ? 1 : -1);
                        B[i] = comb({g, g, g}, B[i + 1]);
                }
                while(m--){
                        int l, r;
                        cin >> l >> r;
                        auto res = comb(A[l - 1], B[r + 1]);
                        cout << res.mx - res.mn + 1 << "\n";
                }
        }
}