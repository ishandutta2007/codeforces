#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int a[N];
int s[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s[i] = s[i - 1] ^ a[i];
        }
        if(n > 100){
                cout << 1 << "\n";
                return 0;
        }
        int res = n + 1;
        for(int i = 1; i <= n; i++){
                for(int j = i; j <= n; j++){
                        for(int h = j + 1; h <= n; h++){
                                int x = s[j] ^ s[i - 1];
                                int y = s[h] ^ s[j];
                                if(x > y){
                                        res = min(res, h - i - 1);
                                }
                        }
                }
        }
        if(res > n){
                res = -1;
        }
        cout << res << "\n";
}