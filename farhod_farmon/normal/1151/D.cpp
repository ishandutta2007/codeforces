#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int b[N];

int cmp(int x, int y)
{
        return b[x] + a[y] < b[y] + a[x];
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < int > ord;
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
                ord.push_back(i);
        }
        sort(ord.begin(), ord.end(), cmp);

        long long res = 0;
        for(int i = 0; i < n; i++){
                int x = ord[i];
                res += 1ll * a[x] * i + 1ll * b[x] * (n - i - 1);
        }

        cout << res << "\n";
}