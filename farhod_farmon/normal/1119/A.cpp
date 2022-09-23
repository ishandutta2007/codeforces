#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
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
        int res = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                if(a[i] != a[1]){
                        res = max(res, i - 1);
                }
                if(a[i] != a[n]){
                        res = max(res, n - i);
                }
        }
        cout << res << "\n";
}