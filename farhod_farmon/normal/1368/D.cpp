#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200100;

using namespace std;

int n;
int a[20];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                for(int j = 0; j < 20; j++){
                        if(x & (1 << j)){
                                a[j] += 1;
                        }
                }
        }
        long long res = 0;
        for(int i = 1; i <= n; i++){
                int x = 0;
                for(int j = 0; j < 20; j++){
                        if(a[j]){
                                x += (1 << j);
                                a[j] -= 1;
                        }
                }
                res += 1ll * x * x;
        }
        cout << res << "\n";
}