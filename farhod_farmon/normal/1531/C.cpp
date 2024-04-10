#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 111;

char a[N][N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int s;
        cin >> s;
        int n = -1, A;
        for(int i = 1; i <= s; i++){
                for(int j = 1; j <= i; j++){
                        if(j * j > s || i * i - (i - j) * (i - j) < s){
                                continue;
                        }
                        if((s - j * j) % 2 == 0){
                                n = i;
                                A = j;
                                break;
                        }
                }
                if(n != -1){
                        break;
                }
        }
        if(n == -1){
                cout << -1 << "\n";
                return 0;
        }

        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        a[i][j] = '.';
                }
        }
        for(int i = 0; i < A; i++){
                for(int j = 0; j < A; j++){
                        a[n - i - 1][j] = 'o';
                }
        }
        s -= A * A;
        s /= 2;
        for(int i = 0; i < A && s; i++){
                int g = min(n - A, s);
                s -= g;

                for(int j = 0; j < g; j++){
                        a[n - A - j - 1][i] = 'o';
                        a[n - i - 1][A + j] = 'o';
                }
        }
        cout << n << "\n";
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        cout << a[i][j];
                }
                cout << "\n";
        }
}