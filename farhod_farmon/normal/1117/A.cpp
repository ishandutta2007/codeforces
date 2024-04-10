#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        int mx = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                mx = max(mx, a[i]);
        }
        int res = 0, cnt = 0;
        a[n + 1] = -1;
        for(int i = 1; i <= n + 1; i++){
                if(a[i] != mx){
                        res = max(res, cnt);
                        cnt = 0;
                }
                else{
                        cnt += 1;
                }
        }
        cout << res << "\n";
}