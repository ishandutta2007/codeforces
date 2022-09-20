#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];
int d[N];
int inf = 1e9;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        for(int i = 0; i < N; i++){
                d[i] = - inf;
        }

        cin >> n;
        int all = 0;
        int res = 0;
        int best = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];

                if(a[i] == a[i - 1]){
                        i -= 1;
                        n -= 1;
                        continue;
                }

                if(i > 1){
                        int x = a[i - 1];
                        d[x] = max(d[a[i]] + 1, best);
                        best = max(best, d[x]);
                }
        }


        for(int i = 0; i < N; i++){
                res = max(res, d[i]);
        }

        cout << n - res << "\n";
}