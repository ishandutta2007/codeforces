#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
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
                int n, m;
                cin >> n >> m;
                int g = n - m + 1;
                for(int i = 1; i <= m - g; i++){
                        cout << i << " ";
                }
                for(int i = 0; i < g; i++){
                        cout << m - i << " ";
                }
                cout << "\n";
        }
}