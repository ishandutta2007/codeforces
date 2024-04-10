#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int q;
int a[N];
int r[N];
int c[N];
int best[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                r[a[i]] = i;
                c[a[i]] += 1;
        }
        int shit = 0, par = 0;
        for(int i = 1; i <= n; i++){
                if(i <= shit){
                        shit = max(shit, r[a[i]]);
                        best[par] = max(best[par], c[a[i]]);
                } else{
                        par = i;
                        shit = r[a[i]];
                        best[par] = c[a[i]];
                }
        }
        int res = n;
        for(int i = 1; i <= n; i++){
                res -= best[i];
        }
        cout << res << "\n";
}