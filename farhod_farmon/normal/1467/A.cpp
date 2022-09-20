#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 110119;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                if(n == 1){
                        cout << 9 << "\n";
                        continue;
                }
                for(int i = 0; i < n; i++){
                        cout << (8 + abs(i - 1)) % 10;
                }
                cout << "\n";
        }
}