#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);


        int n;
        cin >> n;
        vector < int > a(n);
        vector < int > c(n, 0);
        vector < int > bal(n, 1e9);
        int res = 0;
        for(int i = 0; i < n; i++){
                cin >> a[i];
                a[i] -= 1;

                int x = a[i];
                int cur = c[x] - (res - c[x]) + 1;
                if(cur - bal[x] >= 2){
                        continue;
                }
                bal[x] = min(bal[x], cur);
                c[x] += 1;
                res += 1;
        }

        cout << res << "\n";
}