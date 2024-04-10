#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
long long a[N];
long long s[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);

        n--;
        for(int i = 1; i <= n; i++){
                a[i] = a[i + 1] - a[i];
        }
        sort(a + 1, a + n + 1);

        for(int i = 1; i <= n; i++){
                s[i] = s[i - 1] + a[i];
        }

        cin >> m;
        for(int i = 1; i <= m; i++){
                long long l, r;
                cin >> l >> r;
                r -= l;

                int tl = 0, tr = n;
                while(tl < tr){
                        int m = (tl + tr) / 2;
                        if(a[m + 1] <= r + 1){
                                tl = m + 1;
                        } else{
                                tr = m;
                        }
                }

                cout << s[tl] + (r + 1) * (n - tr + 1) << " ";
        }
}