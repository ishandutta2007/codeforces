#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 11;

using namespace std;

int n, a, b, k;

bool can(int t)
{
        int x = min(t, a), y = min(t, b);
        return 1ll * x * ((n + 1) / 2) + 1ll * y * (n / 2) >= 1ll * k * t;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t >> n >> a >> b >> k;
        int l = 0, r = t;
        while(l < r){
                int m = (l + r) / 2;
                if(can(m + 1)){
                        l = m + 1;
                }
                else{
                        r = m;
                }
        }
        cout << l << "\n";
}