#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 100100;
const int Q = 400200;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n, m;
                cin >> n >> m;
                int have = 0, can = 0;
                cin >> have;
                for(int i = 1; i < n; i++){
                        int x;
                        cin >> x;
                        can += x;
                }
                cout << min(m, have + can) << "\n";
        }
}