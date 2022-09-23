#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int last = 0;
        int res = 1;
        cin >> n;
        for(int i = 1; i <= n; i++){
                int x, y;
                cin >> x >> y;
                if(x > y){
                        swap(x, y);
                }
                res += max(0, x - last);
                last = max(last, max(x, y - 1));
        }
        cout << res << "\n";
}