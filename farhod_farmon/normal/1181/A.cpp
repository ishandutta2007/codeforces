#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long a, b, c;
        cin >> a >> b >> c;
        long long res = a / c + b / c;
        a %= c;
        b %= c;
        if(a + b >= c){
                cout << res + 1 << " " << c - max(a, b) << "\n";
        } else{
                cout << res << " " << 0 << "\n";
        }
}