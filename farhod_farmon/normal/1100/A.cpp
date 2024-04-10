#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 440;
const int Q = 250200;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                int cnt = 0;
                for(int j = 1; j <= n; j++){
                        if(j % k != i % k){
                                cnt += a[j];
                        }
                }
                res = max(res, abs(cnt));
        }
        cout << res << "\n";
}