#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const long long mod = 998244353;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int n, a, b;
                cin >> n >> a >> b;
                bool res = false;
                for(int i = 1; i <= a; i++){
                        int x;
                        cin >> x;
                        if(x == n){
                                res = true;
                        }
                }
                for(int i = 1; i <= b; i++){
                        int x;
                        cin >> x;
                }
                cout << (res ? "YES" : "NO") << "\n";
        }
}