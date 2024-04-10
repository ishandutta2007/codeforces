#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        if(n % 2){
                cout << 0 << "\n";
        } else{
                cout << (1ll << n / 2) << "\n";
        }
}