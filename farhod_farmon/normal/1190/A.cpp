#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 150100;
const long long mod = 998244353;

using namespace std;

long long n, m, k;
long long a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        for(int i = 0; i < m; i++){
                cin >> a[i];
        }
        int res = 0;
        for(int i = 0; i < m; i++){
                res += 1;
                int j = i;
                long long r = (a[i] - 1 - i) / k * k + k;
                while(j < m && a[j] - i <= r){
                        j += 1;
                }
                i = j - 1;
        }
        cout << res << "\n";
}