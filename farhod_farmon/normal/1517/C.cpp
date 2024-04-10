#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 555;
const int mod = 1e9 + 7;

int n;
int a[N][N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int A;
                cin >> A;
                int rem = A - 1;
                a[i][i] = A;
                while(rem > 0){
                        int x = i, y = i;
                        while(rem > 0){
                                if(x - 1 >= 1 && !a[y][x - 1]){
                                        x -= 1;
                                } else if(y + 1 <= n && !a[y + 1][x]){
                                        y += 1;
                                } else{
                                        break;
                                }
                                rem -= 1;
                                a[y][x] = A;
                        }
                }
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= i; j++){
                        cout << a[i][j] << " ";
                }
                cout << "\n";
        }
}