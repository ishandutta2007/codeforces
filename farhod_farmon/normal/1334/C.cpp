#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 50005;

using namespace std;


int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                int n;
                cin >> n;
                vector < long long > a(n), b(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i] >> b[i];
                }
                long long res = 0, shit = 1e18;
                for(int i = 0; i < n; i++){
                        int j = (i - 1 + n);
                        if(j >= n){
                                j -= n;
                        }

                        res += max(0ll, a[i] - b[j]);
                        shit = min(shit, min(a[i], b[j]));
                }

                cout << res + shit << "\n";
        }
}