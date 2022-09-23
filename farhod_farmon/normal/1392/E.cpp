#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 66;
const long long mod = 1e9 + 7;

using namespace std;

int n;
long long a[N][N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        if(i + j > 0){
                                a[i][j] = (1ll << i + j - 1);
                        }
                        if(i % 2){
                                a[i][j] = 0;
                        }
                        cout << a[i][j];
                        if(j + 1 == n){
                                cout << endl;
                        } else{
                                cout << " ";
                        }
                }
        }
        int q;
        cin >> q;
        while(q--){
                long long sum;
                cin >> sum;
                int x = 0, y = 0;
                cout << x + 1 << " " << y + 1 << endl;
                for(int i = 0; i < 2 * n - 2; i++){
                        if(x % 2 == 0){
                                if(sum & (1ll << i)){
                                        y += 1;
                                } else{
                                        x += 1;
                                }
                        } else{
                                if(sum & (1ll << i)){
                                        x += 1;
                                } else{
                                        y += 1;
                                }
                        }
                        cout << x + 1 << " " << y + 1 << endl;
                }
        }
}