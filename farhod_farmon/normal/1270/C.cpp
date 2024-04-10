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
                int n;
                cin >> n;
                long long S = 0, A = 0;
                for(int i = 1; i <= n; i++){
                        long long x;
                        cin >> x;
                        S += x;
                        A ^= x;
                }

                cout << 2 << "\n";
                cout << A << " " << S + A << "\n";
        }
}