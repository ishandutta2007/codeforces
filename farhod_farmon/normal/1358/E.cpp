#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;

using namespace std;

int n;
int m;
long long x;
long long a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(false);

        cin >> n;
        m = (n + 1) / 2;
        for(int i = 0; i < m; i++){
                cin >> a[i];
        }
        cin >> x;
        for(int i = m - 1; i >= 0; i--){
                a[i] += a[i + 1];
        }
        for(int i = 0; i < m; i++){
                if(n % 2 == 0){
                        a[i] += x * (i + 1);
                } else{
                        a[i] += x * i;
                }
        }
        int G = 1 - (n & 1);
        long long shit = a[0];
        for(int i = 0; i < m; i++){
                shit = min(shit, a[i]);

                if(shit + x * (m - i - 1) > 0){
                        cout << m + (m - i - 1 + G) << "\n";
                        return 0;
                }
        }

        cout << -1 << "\n";
}