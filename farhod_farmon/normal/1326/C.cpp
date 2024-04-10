#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int k;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        long long res = 0, cnt = 1;
        vector < int > v;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i] > n - k){
                        v.push_back(i);
                        res += a[i];
                }
        }
        for(int i = 1; i < v.size(); i++) cnt = cnt * (v[i] - v[i - 1]) % mod;

        cout << res << " " << cnt << "\n";
}