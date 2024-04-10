#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int k;
int a[N];
int b[N];
int c[N];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                cin >> n >> k;
                for(int i = 1; i <= n; i++){
                        cin >> a[i];
                        if(a[i] < k){
                                a[i] = -1;
                        } else if(a[i] == k){
                                a[i] = 1;
                        } else{
                                a[i] = 2;
                        }
                }
                if(n == 1){
                        cout << (a[1] == 1 ? "yes" : "no") << "\n";
                        continue;
                }
                c[n + 1] = b[0] = -1;
                for(int i = 1; i <= n; i++){
                        b[i] = max(0, b[i - 1]) + min(a[i], 1);
                }
                for(int i = n; i >= 1; i--){
                        c[i] = max(0, c[i + 1]) + min(a[i], 1);
                }
                int res = 0, gg = 0;
                for(int i = 1; i <= n; i++){
                        if(a[i] == -1){
                                continue;
                        } else if(a[i] == 1){
                                gg = 1;
                        }
                        int A = b[i - 1], B = c[i + 1];
                        if(max(A, B) >= 0){
                                res = 1;
                        }
                }
                cout << (res * gg ? "yes" : "no") << "\n";
        }
}