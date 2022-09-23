#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 1000000007;
const int MAGIC = 2000;

using namespace std;

int n;
int r[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> r[i] >> r[i];
        }
        int k, res = 0;
        cin >> k;
        for(int i = 1; i <= n; i++){
                res += r[i] >= k;
        }
        cout << res << "\n";
}