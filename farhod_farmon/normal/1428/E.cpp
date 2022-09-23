#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int k;
int a[N];
int c[N];

long long f(long long x)
{
        return x * x;
}

long long g(long long a, long long c)
{
        return f(a / c) * (c - a % c) + f(a / c + 1) * (a % c);
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        set < pair < long long, int > > S;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                c[i] = 1;
                if(c[i] < a[i]){
                        S.insert({g(a[i], c[i]) - g(a[i], c[i] + 1), i});
                }
        }
        //sort(a + 1, a + n + 1);

        int rem = k - n;
        while(rem--){
                auto i = (--S.end())->se;
                S.erase(--S.end());
                c[i] += 1;
                if(c[i] < a[i]){
                        S.insert({g(a[i], c[i]) - g(a[i], c[i] + 1), i});
                }
        }
        long long res = 0;
        for(int i = 1; i <= n; i++){
                res += g(a[i], c[i]);
        }

        cout << res << "\n";
}