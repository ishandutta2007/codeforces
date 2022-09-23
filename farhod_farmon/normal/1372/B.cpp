#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 400400;
const int mod = 1e9 + 7;

using namespace std;

int n;

void upd(int &x, int y)
{
        y = min(y, n - y);
        if(y > x){
                x = y;
        }
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                cin >> n;
                int x = 1;
                for(int i = 2; i * i <= n; i++){
                        if(n % i) continue;
                        upd(x, i);
                        upd(x, n / i);
                }
                cout << x << " " << n - x << "\n";
        }
}