#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int c[11];

bool good(int x)
{
        for(int i = 0; i < 10; i++){
                c[i] = 0;
        }
        while(x > 0){
                if(c[x % 10]){
                        return false;
                }
                c[x % 10] = 1;
                x /= 10;
        }
        return true;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int l, r;
        cin >> l >> r;
        for(int i = l; i <= r; i++){
                if(good(i)){
                        cout << i << "\n";
                        return 0;
                }
        }
        cout << -1 << "\n";
}