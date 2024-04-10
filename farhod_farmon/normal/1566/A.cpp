#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 7;

using namespace std;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, s;
                cin >> n >> s;
                cout << s / (n / 2 + 1) << "\n";
        }
}