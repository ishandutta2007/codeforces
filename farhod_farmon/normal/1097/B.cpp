#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 15;
const long long mod = 1e9 + 9;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        for(int i = 0; i < (1 << n); i++){
                int res = 0;
                for(int j = 0; j < n; j++){
                        if(i & (1 << j)){
                                res += a[j];
                        }
                        else{
                                res -= a[j];
                        }
                }
                res = (res % 360 + 360) % 360;
                if(res == 0){
                        cout << "YES" << "\n";
                        return 0;
                }
        }
        cout << "NO" << "\n";
}