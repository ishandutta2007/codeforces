#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const long long mod = 1000000007;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        long long s = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s += a[i];
        }
        sort(a + 1, a + n + 1);
        int q;
        cin >> q;
        for(int i = 1; i <= q; i++){
                int k;
                cin >> k;
                cout << s - a[n - k + 1] << "\n";
        }
}