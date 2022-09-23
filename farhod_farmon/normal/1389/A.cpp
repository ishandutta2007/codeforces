#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int l, r;
                cin >> l >> r;
                if(l * 2 <= r) cout << l << " " << l * 2 << "\n";
                else cout << -1 << " " << -1 << "\n";
        }
}