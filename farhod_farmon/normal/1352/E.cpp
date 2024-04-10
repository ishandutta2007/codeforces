#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 8080;

using namespace std;

int n;
int a[N];
int b[N];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                cin >> n;
                for(int i = 1; i <= n; i++){
                        cin >> a[i];
                        b[i] = 0;
                }
                for(int i = 1; i <= n; i++){
                        int cnt = a[i];
                        for(int j = i + 1; j <= n; j++){
                                cnt += a[j];
                                if(cnt <= n){
                                        b[cnt] = 1;
                                }
                        }
                }
                int res = 0;
                for(int i = 1; i <= n; i++){
                        res += b[a[i]];
                }
                cout << res << "\n";
        }
}