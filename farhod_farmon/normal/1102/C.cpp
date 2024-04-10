#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n, a, b;
        cin >> n >> a >> b;
        int res = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                res += (x <= a);
        }
        if(a > b){
                cout << n << "\n";
        }
        else{
                cout << (res + 1) / 2 << "\n";
        }
}