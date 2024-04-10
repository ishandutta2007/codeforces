#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int k;
int a[N];
int b[N];

int f(int x, int y)
{
        if(y < 1 || y > n){
                return 0;
        }
        if(x == y){
                return !a[x];
        }
        return a[x] >= b[y] || (!a[x]);
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> k;
        for(int i = 1; i <= k; i++){
                int x;
                cin >> x;
                if(!a[x]){
                        a[x] = i;
                }
                b[x] = i;
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                res += f(i, i - 1);
                res += f(i, i);
                res += f(i, i + 1);
        }

        cout << res << "\n";
}