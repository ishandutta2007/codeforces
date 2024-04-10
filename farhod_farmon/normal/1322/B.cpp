#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 400400;
const int Q = 20000400;

using namespace std;

int n;
int a[N];
int b[N];
int s[Q];

int get(int l, int r)
{
        if(l >= Q) return 0;
        l = max(l, 0);
        r = min(r, Q - 1);
        return s[r] - (l > 0 ? s[l - 1] : 0);
}

int solve(int k)
{
        for(int i = 0; i < Q; i++) s[i] = 0;
        for(int i = 1; i <= n; i++){
                b[i] = a[i] & ((1 << k + 1) - 1);
                s[b[i]] += 1;
        }
        for(int i = 1; i < Q; i++) s[i] += s[i - 1];

        long long res = 0;
        for(int i = 1; i <= n; i++){
                res += get((1 << k) - b[i], (1 << k + 1) - b[i] - 1);
                res += get((1 << k + 1) + (1 << k) - b[i], (1 << k + 2) - b[i] - 1);

                if((a[i] + a[i]) & (1 << k))res -= 1;
        }
        res /= 2;
        return res % 2;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
                scanf("%d", a + i);
        }
        int res = 0;
        for(int i = 0; i <= 25; i++){
                res += (1 << i) * solve(i);
        }
        printf("%d\n", res);
}