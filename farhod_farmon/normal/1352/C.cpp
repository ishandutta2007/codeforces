#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n, k;
                cin >> n >> k;
                // g * (n - 1) <= k;
                int g = (k - 1) / (n - 1);
                k %= n - 1;
                if(k == 0){
                        k = n - 1;
                }
                cout << g * n + k << "\n";
        }
}