#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int m;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        vector < int > v;
        for(int i = 2; i <= n; i++){
                v.push_back(a[i] - a[i - 1]);
        }
        sort(v.begin(), v.end());
        long long res = n;
        k = n - k;
        for(int i = 0; i < k; i++){
                res += v[i] - 1;
        }
        cout << res << "\n";
}