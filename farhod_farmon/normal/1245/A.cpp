#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                int a, b;
                cin >> a >> b;
                if(__gcd(a, b) != 1){
                        cout << "Infinite\n";
                } else{
                        cout << "Finite\n";
                }
        }
}