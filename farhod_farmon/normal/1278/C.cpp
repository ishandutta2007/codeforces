#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
map < int, int > c;

void solve()
{
        cin >> n;
        c.clear();
        int s = 0;
        for(int i = 1; i <= n + n; i++){
                cin >> a[i];
                a[i] = (a[i] == 1 ? 1 : -1);

                s += a[i];
                if(i <= n){
                        c[s] = n - i;
                }
        }

        int res = 2 * n;
        if(c.find(0) != c.end()){
                res = c[0] + n;
        } else{
                c[0] = n;
        }
        s = 0;
        for(int i = n + n; i > n; i--){
                s += a[i];
                if(c.find(-s) != c.end()){
                        res = min(res, c[-s] + i - n - 1);
                }
        }

        cout << res << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}