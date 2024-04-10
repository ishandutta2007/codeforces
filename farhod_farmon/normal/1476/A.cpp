#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                long long n, k;
                cin >> n >> k;
                long long need = ((n - 1) / k + 1) * k;
                cout << (need - 1) / n + 1 << "\n";
        }
}