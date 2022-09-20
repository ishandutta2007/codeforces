#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int q;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        int s = 0;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s += a[i];
        }
        for(int i = 1; i <= q; i++){
                int t, x;
                cin >> t >> x;
                if(t == 1){
                        s -= a[x];
                        a[x] ^= 1;
                        s += a[x];
                } else{
                        cout << (s >= x ? 1 : 0) << "\n";
                }
        }
}