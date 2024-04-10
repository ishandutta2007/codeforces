#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

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
                int A = 0, B = 0;
                for(int i = 0, s = 0; i < n; i++){
                        int x;
                        cin >> x;
                        s += x;
                        A = max(A, s);
                }
                int m;
                cin >> m;
                for(int i = 0, s = 0; i < m; i++){
                        int x;
                        cin >> x;
                        s += x;
                        B = max(B, s);
                }
                cout << A + B << "\n";
        }
}