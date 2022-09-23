#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                }
                int res = 0;
                vector < int > d(n, 0);
                for(int i = 1, j = 0, h = 1; i < n; i++){
                        if(i + 1 == n || a[i] > a[i + 1]){
                                while(h <= i){
                                        d[h] = d[j] + 1;
                                        h += 1;
                                }
                                j += 1;
                        }
                        res = max(res, d[i]);
                }
                cout << res << "\n";
        }
}