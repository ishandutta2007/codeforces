#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const int mod = 1e9 + 7;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                long long x;
                cin >> x;
                if(x <= 14){
                        cout << "NO" << "\n";
                        continue;
                }
                x %= 14;
                if(x >= 1 && x <= 6){
                        cout << "YES" << "\n";
                } else{
                        cout << "NO" << "\n";
                }
        }
}