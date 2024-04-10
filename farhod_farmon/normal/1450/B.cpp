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
                int n, k;
                cin >> n >> k;
                vector < int > a(n), b(n);
                for(int i =0 ; i < n; i++){
                        cin >> a[i] >> b[i];
                }
                int res = -1;
                for(int i = 0; i < n; i++){
                        int cnt = 0;
                        for(int j = 0; j < n; j++){
                                if(abs(a[i] - a[j]) + abs(b[i] - b[j]) <= k){
                                        cnt += 1;
                                }
                        }
                        if(cnt == n){
                                res = 1;
                        }
                }
                cout << res << "\n";
        }
}